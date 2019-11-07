#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include<tuple>
#include <algorithm>
#include<queue>
using namespace std;

int N;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int visit[301][301];
int dist[901][901];
int conns[901];
int gcount;

int find(int x) {
    if (conns[x] == x) {
        return x;
    } else {
        return find(conns[x]);
    }
}
void cunion(int x, int y){
    x = find(x);
    y = find(y);

    conns[y] = x;
}

bool valid(int x, int y){
    return (x>=0&&x<N&&y>=0&&y<N);
}
void groupSearch(const vector<vector<int>>& land,const int height,int x, int y){
    visit[x][y]=gcount;
    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i]))
            if(visit[x+dx[i]][y+dy[i]]==0&&abs(land[x+dx[i]][y+dy[i]]-land[x][y])<=height)
                groupSearch(land,height,x+dx[i],y+dy[i]);
    }
}
int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    N=land.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(visit[i][j]==0){
                gcount++;
                groupSearch(land,height,i,j);
            }
    }

    vector<vector<pair<int,int>>> groups(gcount+1);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            groups[visit[i][j]].push_back(make_pair(i,j));
    for(int i=0;i<901;i++)
        for(int j=0;j<901;j++)
            dist[i][j]=-1;
    
    for(int i=1;i<=gcount;i++){
        for(auto& loc : groups[i]){
            for(int j=0;j<4;j++){
                int nx=loc.first+dx[j];
                int ny=loc.second+dy[j];
                if(valid(nx,ny)&&visit[nx][ny]!=i){
                    if(dist[i][visit[nx][ny]]==-1 || abs(land[nx][ny]-land[loc.first][loc.second])<dist[i][visit[nx][ny]]){
                        dist[i][visit[nx][ny]]=abs(land[nx][ny]-land[loc.first][loc.second]);
                        dist[visit[nx][ny]][i]=abs(land[nx][ny]-land[loc.first][loc.second]);
                    }
                }
            }
        }
    }
    vector<tuple<int,int,int>> edge;
    for(int i=1;i<gcount;i++)
        for(int j=i+1;j<=gcount;j++){
            if(dist[i][j]!=-1)
                edge.push_back(make_tuple(dist[i][j],i,j));
        }
    sort(edge.begin(),edge.end());
    for(int i=0;i<901;i++)
        conns[i]=i;
    int t=0;
    for(int i=0;i<edge.size();i++){
        int d,from,to;
        tie(d,from,to)=edge[i];
        if((find(from)!=find(to))){
            cunion(from,to);
            t++;
            answer+=d;
        }
        if(t==gcount-1)
            break;
    }

    return answer;
}