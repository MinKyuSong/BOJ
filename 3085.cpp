#include <cstdio>
using namespace std;

char candymap[51][51];
int n;

int check(int x, int y)
{
    int h=0,v=0;

    for(int i=x;i<n;i++)
        if(candymap[i][y]==candymap[x][y])
            h++;
        else
            break;
        
    for(int i=x;i>=0;i--)
        if(candymap[i][y]==candymap[x][y])
            h++;
        else
            break;

    for(int i=y;i<n;i++)
        if(candymap[x][i]==candymap[x][y])
            v++;
        else
            break;
        
    for(int i=y;i>=0;i--)
        if(candymap[x][i]==candymap[x][y])
            v++;
        else
            break;
    h--;v--;
    return h>v?h:v;
}

int main(void)
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", candymap[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int temp=check(i,j);
            if(temp>ans)
                ans=temp;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            char t = candymap[i][j];
            candymap[i][j] = candymap[i][j + 1];
            candymap[i][j + 1] = t;

            int temp=check(i,j);
            if(temp>ans)
                ans=temp;
            
            temp=check(i,j+1);
            if(temp>ans)
                ans=temp;
            

            t = candymap[i][j];
            candymap[i][j] = candymap[i][j + 1];
            candymap[i][j + 1] = t;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char t = candymap[i][j];
            candymap[i][j] = candymap[i + 1][j];
            candymap[i + 1][j] = t;

            int temp=check(i,j);
            if(temp>ans)
                ans=temp;
            
            temp=check(i+1,j);
            if(temp>ans)
                ans=temp;

            t = candymap[i][j];
            candymap[i][j] = candymap[i + 1][j];
            candymap[i + 1][j] = t;
        }
    }
    printf("%d\n", ans);
    return 0;
}