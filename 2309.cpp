#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    vector<int> heights(9);
    vector<int> ans;
    int sum=0;
    for(int i=0;i<9;i++)
    {
        cin>>heights[i];
        sum+=heights[i];
    }

    int spy1,spy2;
    for(int i=0;i<8;i++)
    {
        bool flag=false;
        spy1=i;
        for(int j=i+1;j<9;j++)
        {
            spy2=j;
            if(sum-heights[i]-heights[j]==100)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int i=0;i<9;i++)
    {
        if(i!=spy1&&i!=spy2)
            ans.push_back(heights[i]);
    }
    sort(ans.begin(),ans.end());
    for(int &i : ans)
    {
        cout<<i<<endl;
    }
    return 0;
}