#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
bool com(tuple<int,int,float> &t1,tuple<int,int,float>&t2)
{
    return get<2>(t1)>get<2>(t2);
}
int main()
{
    freopen("knapsack.txt","r",stdin);
    int w;
    cin>>w;
    vector<tuple<int,int,float>> v;
    int x,y;
    while(cin>>x>>y)
    {
        v.push_back(make_tuple(x,y,y/x));
    }
    sort(v.begin(),v.end(),com);
    int u=0;
    for(auto it:v)
    {
        if(w>=get<0>(it)) 
        {
            u+=get<1>(it);
            w-=get<0>(it);
        }
        else if(w<get<0>(it)) 
        {
            u+=w*get<2>(it);
            w=0;
        }
        if(!w) break;
    }
    cout<<u<<endl;


}