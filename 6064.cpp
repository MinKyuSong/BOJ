#include<iostream>
using namespace std;

int gcd(int x, int y)
{
    int a=(x>y)?x:y;
    int b=(x>y)?y:x;
    while(b>0)
    {
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

long long lcm(int x, int y)
{
    return x*y/gcd(x,y);
}

int main(void)
{
    int n;
    cin>>n;
    while(n--)
    {
        int M,N,x,y;
        cin>>M>>N>>x>>y;
        int ans=-1;
        x-=1;y-=1;
        long long endDay=lcm(M,N);
        
        for(int i=x;i<=endDay;i+=M)
        {
            if(i%N==y)
            {
                ans=i+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}