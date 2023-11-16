#include<iostream>
#include<tuple>
#include<vector>
#include<map>
using namespace std;
map<string, vector< pair< string,int >>> input()
{
    if(freopen("floydInput.txt","r",stdin)==NULL) cout<<"!F\n";
    map<string, vector< pair< string,int >>>graph;
    int nE;
    cin>>nE;
    for(int i=0;i<nE;++i)
    {
        string src,dst;
        int wt;
        cin>>src>>dst>>wt;
        graph[src].push_back(make_pair(dst,wt));
        graph[dst].push_back(make_pair(src,wt));
    }
    return graph;
}
void printGraph(map<string, vector< pair< string,int >>> graph)
{
    for(auto it:graph)
    {
        string src=it.first;
        vector<pair<string,int>> edges=it.second;
        cout<<"Vertex "<<src<<" is connected to \n";
        for(auto it2:edges)
        {
            string dst=it2.first;
            int wt=it2.second;
            cout<<"    vertex "<<dst<<" with weight "<<wt<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    map<string, vector< pair< string,int >>>graph=input();
    printGraph(graph);
}