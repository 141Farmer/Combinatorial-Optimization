#include<iostream>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;
vector<vector<int> >graph;
vector<vector<int> >d;
vector<vector<int> >p;
vector<string > city;
int nV,nE;
unordered_map<string,int> cont;
const int inf=INT_MAX;
void input()
{
      cout<<"Enter inputs \n";
      FILE *fp=freopen("floydInput.txt","r",stdin);
      cin>>nE;
      int i;
      graph.resize(nE,vector<int>(nE,inf));
      nV=0;
      for(i=0;i<nE;++i)
      {
            string u,v;
            int w;
            cin>>u>>v>>w;
            if(i==0) 
            {
                  cont[u]=nV;
                  cont[v]=++nV;
                  graph[cont[u]][cont[v]]=w;
                  city.push_back(u);
                  city.push_back(v);
                  continue;
            }
            if(cont.find(u)==cont.end())
            {
                  cont[u]=++nV;
                  city.push_back(u);
            }
            if(cont.find(v)==cont.end())
            {
                  cont[v]=++nV;
                  city.push_back(v);
            }
            graph[cont[u]][cont[v]]=w;
      }
      ++nV;
      fclose(fp);
      freopen("CON","r",stdin);
}
vector<vector<int> > floydWarshall()
{
      vector<vector<int> >d(nV,vector<int>(nV,inf));
      p.resize(nV,vector<int>(nV,0));
      int i=0,j,k;
      for(i=0;i<nV;++i)
      {
            for(j=0;j<nV;++j)
            {
                  d[i][j]=graph[i][j];
            }
      }
      for(i=0;i<nV;++i)
      {
            d[i][i]=0;
      }
      for(int i=0;i<p.size();++i)
      {
            for(int j=0;j<p.size();++j)
            {
                  if(i==j or graph[i][j]==inf) p[i][j]=0;
                  else if(i!=j and graph[i][j]!=inf) p[i][j]=i;
            }
      }
      for(k=0;k<nV;++k)
      {
            for(i=0;i<nV;++i)
            {
                  for(j=0;j<nV;++j)
                  {
                        if(d[i][j]!=inf and d[j][k]!=inf and d[k][j]!=inf)
                             if(d[i][k]+d[k][j]<d[i][j])
                             {
                                   d[i][j]=d[i][k]+d[k][j];
                                   p[i][j]=p[k][j];
                             }
                  }
            }
      }
      return d;
}
void path()
{
      d=floydWarshall();
      int i,j;
      for(i=0;i<nV;++i)
      {
            for(j=0;j<nV;++j)
            {
                  if(d[i][j]==inf) cout<<"Infinity  ";
                  else cout<<d[i][j]<<"         ";
            }
            cout<<endl;
      }
      cout<<endl;
}
void printPath(int s,int t)
{
      if(p[s][t]==0) 
      {
            cout<<"No path";
            return;
      }
      else if(p[s][t]==s) cout<<city[s]<<" ";
      else
      {
            printPath(s,p[s][t]);
            printPath(p[s][t],t);
      }
      cout<<city[t]<<" ";

}
void route()
{
      for(int i=0;i<nV;++i)
      {
            for(int j=0;j<nV;++j)
            {
                  if(i!=j) 
                  {
                        cout<<"shortest path from "<<city[i]<<" to "<<city[j]<<" is \n";
                        printPath(i,j);
                        cout<<endl;
                  }
            }
      }
      
}

int main()
{
      input();
      path();    
      route();
}