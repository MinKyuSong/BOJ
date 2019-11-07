#include<iostream>
using namespace std;

int main(void)
{
    int E,S,M;
    cin>>E>>S>>M;

    int e=1, s=1,m=1;
    int ans=1;
    while((e!=E)||(s!=S)||(m!=M))
    {
        ans++;
        e=(e+1)%16;
        if(e==0)
            e++;

        s=(s+1)%29;
        if(s==0)
            s++;

        m=(m+1)%20;
        if(m==0)
            m++;
    }
    cout<<ans<<endl;
    return 0;
}