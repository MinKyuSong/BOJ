#include<iostream>
#include<vector>
using namespace std;

bool check[10];
int result=0;
int n;
void solution(int i, int idx,vector<int>&ans,const vector<int>&inputs)
{
    check[i]=true;
    ans[idx]=inputs[i];
    for(int j=0;j<n;j++)
        if(!check[j])
            solution(j,idx+1,ans,inputs);
    check[i]=false;
    
    if(idx==n-1)
    {
        int temp=0;
        for(int j=0;j<n-1;j++)
            temp+=abs(ans[j]-ans[j+1]);
        if(temp>result)
            result=temp;
    }
}

int main(void)
{
    cin.tie(NULL);cout.tie(NULL);ios_base::sync_with_stdio(false);
    cin>>n;
    vector<int> inputs(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++)
        cin>>inputs[i];
    for(int i=0;i<n;i++)
    {
        solution(i,0,ans,inputs);
    }
    cout<<result<<endl;
    
    return 0;
}