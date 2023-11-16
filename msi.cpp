#include<iostream>
using namespace std;
long msiBf(int arr[],int n)
{
    long sum=arr[0];
    for(int i=0;i<n;++i)
    {
        long ts=arr[i];
        for(int j=i+1;j<n;++j)
        {
            ts+=arr[j];
            sum=max(sum,ts);
        }
    }
    return sum;
}
long msiDp(int arr[],int n,int &a,int &b)
{
    long sum=0,ts=arr[0];
    a=0;
    b=0;
    for(int i=1;i<n;++i)
    {
        if(arr[i]>ts+arr[i])
        {
            a=i;
            ts=arr[i];
        }
        else ts+=arr[i];
        if(sum<ts)
        {
            sum=ts;
            b=i;
        }
    }
    return sum;

}
int main()
{
    int arr[]={2,-5,9,-3,1,7,-15,2,3};
    int n=sizeof(arr)/sizeof(int);
    int a,b;
    cout<<msiBf(arr,n)<<endl;
    cout<<msiDp(arr,n,a,b)<<" "<<a<<" "<<b<<endl;
}