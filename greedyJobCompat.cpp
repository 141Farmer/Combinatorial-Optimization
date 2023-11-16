#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct job
{
    int start,finish;
    bool compat=true;
    string id;
};
vector<job> jobs;
bool finishTime(job& j1,job& j2)
{
    return j1.finish<j2.finish;
}
void readInput()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>jobs[i].id>>jobs[i].start>>jobs[i].finish;
    }
}
int select(int i)
{
    int n=jobs.size();
    int m=i+1;
    while(m<=n and jobs[i].finish>jobs[m].start)
    {
        jobs[m].compat=0;
        ++m;
    }
    if(m<=n) return select(m);
    return 0;
}
int main()
{
    int n=11,i,j;
    jobs.resize(n);
    /*for (int i = 0; i < n; ++i)
    {
        cin >> jobs[i].id >> jobs[i].start >> jobs[i].finish;
    }*/
    freopen("input.txt","r",stdin);
    readInput();
    sort(jobs.begin(), jobs.end(), finishTime);
    cout<<endl;
    /*for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(jobs[i].finish >= jobs[j].start and jobs[i].compat)
            {
                jobs[j].compat=0;
            }
        }
    }*/
    select(0);
    for(auto it:jobs)
    {
        if(it.compat)
           cout<<it.id<<" "<<it.start<<" "<<it.finish<<endl;
    }
    return 0;
}
