#include<iostream>
#include<cstdlib>
using namespace std;

bool buttons[10];
int clicks(int channel)
{
    if(channel==0)
        return buttons[0]?0:1;
    int digits=0;
    while(channel>0)
    {
        if(buttons[channel%10])
            return 0;
        channel/=10;
        digits++;
    }
    return digits;
}

int main(void)
{
    int target;
    cin>>target;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        buttons[t]=true;
    }
    int ans=abs(target-100);
    for(int i=0;i<=1000000;i++)
    {
        int c=i;
        int temp=clicks(c);
        if(temp>0)
            if(abs(target-c)+temp<ans)
                ans=abs(target-c)+temp;
    }
    cout<<ans<<endl;
    return 0;
}