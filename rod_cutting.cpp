#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> pricePerSize;
vector<int> maxRevenuePerSize;
vector<int> rodsPerSize;

int cut_rod(int n)
{
      if(maxRevenuePerSize[n]>0) 
        return maxRevenuePerSize[n];
      
      if(n==0) 
        return 0;

      int temp=-1;
      for(int i=0;i<n;++i)
      {
           int q=pricePerSize[i]+cut_rod(n-1-i);
           if(temp<q)
           {
               temp=q;
               rodsPerSize[n]=i+1;
           }
      }
      return maxRevenuePerSize[n]=temp;
}

int main()
{
      int n,i;
      freopen("rodInput.txt","r",stdin);
      cin>>n;
      pricePerSize.resize(max(11,n+1));
      maxRevenuePerSize.resize(max(11,n+1));
      rodsPerSize.resize(max(11,n+1));
      for(i=0;i<10;++i)
      {
            cin>>pricePerSize[i];
      }
      cout<<cut_rod(n)<<endl;
      while(n>0)
      {
          cout<<rodsPerSize[n]<<" ";
          n-=rodsPerSize[n];
      }
      cout<<endl;
      for(int i:rodsPerSize) cout<<i<<" ";
}