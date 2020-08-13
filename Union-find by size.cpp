#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void makeset(int *s, int n)
{
 for(int i=0;i<n;i++)
    s[i]=-1;
}

int find(int s[],int n, int x)
{
    if(!(x>=0 && x<n))
        return-1;
    if(s[x]==-1)
        return x;
    else return find(s,n,s[x]);
}
void union_size(int *s,int n,int root1,int root2)
{
    if((find(s,n,root1)==find(s,n,root2))&& find(s,n,root1)!=-1)
        return;
    if(s[root2]<s[root1])
    {
        s[root2]+=s[root1];
        s[root1]=root2;
        
    }
    else
    {
        s[root1]+=s[root2];
        s[root2]=root1;
    }
}

int main()
{
    int s[10];
    int n=10;
    makeset(s,n);
    int x=4;
    cout<<endl<<"Set of "<<x<<" is "<<find(s,n,x)<<endl;
    union_size(s,n,4,6);
    for(int i=0;i<n;i++)
        cout<<i<<"->"<<s[i]<<" ";
    cout<<endl<<"Set of "<<x<<" is "<<find(s,n,x)<<endl;
    return 0;
}
