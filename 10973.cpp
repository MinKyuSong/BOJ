#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> vInputs(n);
    for(int i=0;i<n;i++)
        cin>>vInputs[i];

    bool check=true;
    int idx;
    for(int i=n-1;i>0;i--)
    {
        if(vInputs[i-1]>vInputs[i])
        {
            check=false;
            idx=i;
            break;
        }
    }
    if(check)
    {
        cout<<-1;
    }
    else
    {
        for(int i=n-1;i>=idx;i--)
        {
            if(vInputs[i]<vInputs[idx-1])
            {
                int temp=vInputs[i];
                vInputs[i]=vInputs[idx-1];
                vInputs[idx-1]=temp;
                break;
            }
        }
        reverse(vInputs.begin()+idx,vInputs.end());

        for(int i=0;i<n;i++)
            cout<<vInputs[i]<<" ";
    }
    cout<<endl;
    return 0;
}