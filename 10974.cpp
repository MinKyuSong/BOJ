#include<iostream>
#include<vector>
using namespace std;

bool check[10];

void solution(int i, int idx,vector<int>&ans, int n)
{
    check[i]=true;
    ans[idx]=i;
    for(int j=1;j<=n;j++)
        if(!check[j])
            solution(j,idx+1,ans,n);
    check[i]=false;
    
    if(idx==n-1)
    {
        for(int j=0;j<n-1;j++)
            cout<<ans[j]<<" ";
        cout<<ans[n-1]<<'\n';
    }
}

int main(void)
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> ans(n);
    for(int i=1;i<=n;i++)
    {
        solution(i,0,ans,n);
    }
}