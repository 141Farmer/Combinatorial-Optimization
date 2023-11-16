#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> p; // weight value
int knpsk(int index,int capacity)
{
    if(index<0 or capacity<=0) return 0;
    if(p[index].first>capacity) return knpsk(index-1,capacity);
    int included=p[index].second+knpsk(index-1,capacity-p[index].first);
    int excluded=knpsk(index-1,capacity);
    return max(included,excluded);
}
int main()
{
    freopen("knapsack.txt","r",stdin);
    int w;
    cin>>w;
    int x,y;
    while(cin>>x>>y)
    {
        p.push_back(make_pair(x,y));
    }
    int l=p.size();
    cout<<knpsk(l,w);
}