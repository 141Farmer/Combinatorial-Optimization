#include<iostream>
#include<vector>
using namespace std;
vector<int> v1={1,2,3,4,5,6,7,8};
vector<int> v2={3,4,6};
int lcsBruteForce()
{
    int n1=v1.size(),n2=v2.size(),i,j;
    int mx=0;
    for(i=0;i<n1;++i)
    {
        for(j=0;j<n2;++j)
        {
            int k=i;
            int l=j;
            int c=0;
            while((k<n1 or j<n2) and v1[k]==v2[l])
            {
                ++c;
                if(k<n1) ++k;
                if(l<n2) ++l;
            }
            mx=max(mx,c);
        }
    }
    return mx;

}
int main()
{
    
    cout<<lcsBruteForce()<<endl;

}