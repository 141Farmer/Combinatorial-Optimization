#include<iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("lisInput.txt","r",stdin);
    int x;
    vector<int> arr;
    while(cin>>x)
    {
        arr.push_back(x);
    }
    int i,j,n=arr.size();
    int lis=0;
    for(i=0;i<n;++i)
    {
        int c=0;
        for(j=i+1;j<n;++j)
        {
            if(arr[i]<arr[j])
            {
                ++c;
            }
        }
        cout<<c<<endl;
        lis=max(lis,c);
    }
    cout<<lis<<endl;

}