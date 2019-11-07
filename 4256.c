#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000

int pre_trav[MAXN];
int in_trav[MAXN];

void cleartrav(){
    int i;
    for(i=0;i<MAXN;i++){
        pre_trav[i]=0;
        in_trav[i]=0;
    }
    return;
}
void gettrav(int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&pre_trav[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&in_trav[i]);
    }
    return;
}

int main(void){
    int nTry,nLen,i;
    
    scanf("%d",&nTry);
    for(i=0;i<nTry;i++){

    }
}