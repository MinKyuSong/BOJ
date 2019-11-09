#include<iostream>
using namespace std;

int map[501][501];

int main(void)
{
    int ans=0;

    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;x++)
        for(int y=0;y<m;y++)
            cin>>map[x][y];
    
    for(int x=0;x<n;x++)
        for(int y=0;y<m;y++)
        {
            int temp=0;
            if(x<=n-4)
            {
                temp=map[x][y]+map[x+1][y]+map[x+2][y]+map[x+3][y];
                if(temp>ans)
                    ans=temp;
            }
            if(y<=m-4)
            {
                temp=map[x][y]+map[x][y+1]+map[x][y+2]+map[x][y+3];
                if(temp>ans)
                    ans=temp;
            }
            if((x<=n-3)&&(y<=m-2))
            {
                temp=map[x][y]+map[x+1][y]+map[x+2][y]+map[x+2][y+1];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y]+map[x+1][y]+map[x+2][y]+map[x+1][y+1];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y]+map[x+1][y]+map[x+2][y]+map[x][y+1];
                if(temp>ans)
                    ans=temp;
                
                temp=map[x][y+1]+map[x+1][y+1]+map[x+2][y+1]+map[x+2][y];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y+1]+map[x+1][y+1]+map[x+2][y+1]+map[x+1][y];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y+1]+map[x+1][y+1]+map[x+2][y+1]+map[x][y];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y]+map[x+1][y]+map[x+1][y+1]+map[x+2][y+1];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y+1]+map[x+1][y+1]+map[x+1][y]+map[x+2][y];
                if(temp>ans)
                    ans=temp;
            }
            if((x<=n-2)&&(y<=m-3))
            {
                temp=map[x][y]+map[x][y+1]+map[x][y+2]+map[x+1][y];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y]+map[x][y+1]+map[x][y+2]+map[x+1][y+1];
                if(temp>ans)
                    ans=temp;

                temp=map[x][y]+map[x][y+1]+map[x][y+2]+map[x+1][y+2];
                if(temp>ans)
                    ans=temp;
                
                temp=map[x+1][y]+map[x+1][y+1]+map[x+1][y+2]+map[x][y];
                if(temp>ans)
                    ans=temp;
                
                temp=map[x+1][y]+map[x+1][y+1]+map[x+1][y+2]+map[x][y+1];
                if(temp>ans)
                    ans=temp;
                    
                temp=map[x+1][y]+map[x+1][y+1]+map[x+1][y+2]+map[x][y+2];
                if(temp>ans)
                    ans=temp;
                
                temp=map[x][y]+map[x][y+1]+map[x+1][y+1]+map[x+1][y+2];
                if(temp>ans)
                    ans=temp;
                
                temp=map[x+1][y]+map[x+1][y+1]+map[x][y+1]+map[x][y+2];
                if(temp>ans)
                    ans=temp;
            }
            if((x<=n-2)&&(y<=m-2))
            {
                temp=map[x][y]+map[x][y+1]+map[x+1][y]+map[x+1][y+1];
                if(temp>ans)
                    ans=temp;
            }
        }

    cout<<ans<<endl;
    return 0;
}