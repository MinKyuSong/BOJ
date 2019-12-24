#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#include <vector>

using namespace std;

int n, gcount;
int map[100][100];
int group[100][100];
int dist[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return x < n && x >= 0 && y < n && y >= 0;
}

void makeGroup(int i, int j)
{
    group[i][j] = gcount;
    queue<pair<int, int>> qSearch;
    qSearch.push(make_pair(i, j));

    while (!qSearch.empty())
    {
        int x, y;
        tie(x, y) = qSearch.front();
        qSearch.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny))
                if(map[nx][ny]==1 && group[nx][ny]==0)
                {
                    group[nx][ny]=gcount;
                    qSearch.push(make_pair(nx,ny));
                }
        }
    }
}


int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    gcount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 && group[i][j] == 0)
            {
                gcount++;
                makeGroup(i, j);
            }
        }
    }

    queue<pair<int, int>> qSearch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j]==1)
                qSearch.push(make_pair(i,j));
        }
    }

    int result=n+n+1;
    while(!qSearch.empty())
    {
        int x,y;
        tie(x,y)=qSearch.front();
        qSearch.pop();

        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(valid(nx,ny))
                if(map[nx][ny]==0)
                {
                    if(group[nx][ny]!=group[x][y])
                    {
                        if(group[nx][ny]==0)
                        {
                            group[nx][ny]=group[x][y];
                            dist[nx][ny]=dist[x][y]+1;
                            qSearch.push(make_pair(nx,ny));
                        }
                        else
                        {
                            if(result>dist[x][y]+dist[nx][ny])
                                result=dist[x][y]+dist[nx][ny];
                        }
                    }
                }
        }
    }

    cout<<result<<endl;
    return 0;
}