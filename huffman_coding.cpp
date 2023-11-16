#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class tree
{
    public:
    char data;
    tree *left,*right;
    unsigned freq;
    tree(char ch,unsigned f)
    {
        data=ch;
        freq=f;
        left=right=NULL;
    }
};
vector<int> freqSum;
vector<tree> huff;
tree* huffman(pair<vector<char>,vector<int>>&trees)
{
    int n=trees.first.size(),i;
    freqSum.resize(n);
    freqSum[0]=*min_element(trees.second.begin(),trees.second.end());
    int freq1=*min_element(trees.second.begin(),trees.second.end());
    int index1=find(trees.second.begin(),trees.second.end(),freq1)-trees.second.begin();
    tree* left=new tree(trees.first[index1],freq1);
    trees.second[index1]=INT_MAX;
    huff.push_back(*left);
    for(i=0;i<n-1;++i)
    { 
        int freq2=*min_element(trees.second.begin(),trees.second.end());
        int index2=find(trees.second.begin(),trees.second.end(),freq2)-trees.second.begin();
        trees.second[index2]=INT_MAX;
        tree* right=new tree(trees.first[index2],freq2);
        huff.push_back(*right);
        freqSum[i+1]=freqSum[i]+freq2;
        tree* z=new tree('!',freqSum[i+1]);
        huff.push_back(*z);
    }
    cout<<endl;
    return &huff.back();
}
int main()
{
    vector<char> chars={'a','b','c','d','e','f'};
    vector<int> freq={45,13,12,16,9,5};
    pair<vector<char>,vector<int>>trees(chars,freq);
    tree* root=huffman(trees);
    freqSum.erase(freqSum.begin());
    for(auto it:freqSum) 
    {
        cout<<it<<endl;
    }
    for(auto it:huff)
    {
        cout<<it.data<<" "<<it.freq<<endl;
    }
}