#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
ll fibb_static(ll n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fibb_static(n-1)+fibb_static(n-2);

}
vector<ll> memo;
ll fibb_dynamic(ll n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(memo.size()<n and memo[n]!=-1) return memo[n];
    if(memo.size()<=n) memo.resize(n+1,-1);
    memo[n]=fibb_dynamic(n-1)+fibb_dynamic(n-2);
    return memo[n];
}
int main()
{
    ll n=10;
    ll a[n];
    cout<<fibb_static(40)<<endl<<fibb_dynamic(40)<<endl;
}