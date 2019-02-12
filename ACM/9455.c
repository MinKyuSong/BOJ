#include<stdio.h>
#include<stdlib.h>

#define MAXN 100

int map [MAXN][MAXN];
int boxmove[MAXN];
int boxcount[MAXN];
void mapclear(){
    int i,j;
    for(i=0;i<MAXN;i++)
        for(j=0;j<MAXN;j++)
            map[i][j]=0;
}
void boxclear(){
    int i;
    for(i=0;i<MAXN;i++){
        boxmove[i]=0; boxcount[i]=0;
    }
    return;
}
void getmap(int n, int m){
    int i, j, temp;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&temp);
            map[i][j]=temp;
            if(temp==1){
                boxcount[j]++;
            }
        }
    return;
}
int calcount(int n, int m){
    int i,j, nCount;
    int target;
    nCount=0;

    for(j=0;j<m;j++)
        for(i=0;i<n;i++){
            if(map[i][j]==1){
                target=n-boxcount[j];
                nCount+=target-i;
                boxcount[j]--;
            }
        }

    return nCount;
}
int main(void){
    int nTry, nResult;
    int i,n,m;
    
    scanf("%d",&nTry);
    
    for(i=0;i<nTry;i++){
        mapclear(); boxclear();
        scanf("%d %d",&n,&m);
        getmap(n,m);
        nResult=calcount(n,m);
        printf("%d\n",nResult);
    }
}