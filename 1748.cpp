#include<iostream>
using namespace std;

int mypow(int n)
{
    int res=1;
    for(int i=0;i<n;i++)
        res*=10;
    return res;
}
int main(void)
{
    long long ans=0;
    string szInput;
    cin>>szInput;
    int digits=szInput.length();
    for(int i=1;i<digits;i++)
    {
        ans+=(mypow(i)-mypow(i-1))*i;
    }
    ans+=(atoi(szInput.c_str())-mypow(digits-1)+1)*digits;
    
    cout<<ans<<endl;
    return 0;
}
