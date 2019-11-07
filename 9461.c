#include<stdio.h>

int main(void){
    int temp1,temp2,temp3,i,j, nTry, nInput,nResult;

    scanf("%d",&nTry);

    for(i=0;i<nTry;i++){
        scanf("%d",&nInput);
        nResult=temp1=temp2=temp3=1;
        for(j=3;j<nInput;j++){
            nResult=temp1+temp2;
            temp1=temp2;
            temp2=temp3;
            temp3=nResult;
        }
        printf("%d\n",nResult);
    }
    return 0;
}