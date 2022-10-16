#include <stdio.h>
#include <stdlib.h>

int min=10000, max=-10000;
int *num;
int k; // 피연산자의 갯수 

/*
    숫자들의 순서는 그대로 두고 
    연산자만 모든 순서대로 배치한다. 
    사용한 op_code 는 --한다. 

*/


void operate(int op_code, int n, int op1, int operator[4]){ 

    operator[op_code]--;
    for(int i=0;i<k;i++) printf("%d  ", operator[i]);

    int result;
    int op2=num[n];
 
    switch(op_code){
        case 0:
        result = op1+op2;
        break;
        case 1:
        result = op1-op2;
        break;
        case 2:
        result = op1*op2;
        break;
        case 3:
        result = op1/op2;
        break;
    }

    //printf("op_code = %d, n = %d, result = %d, %d, -> %d\n", op_code, n, op1, op2, result);
    if(n>=k-1){ // 다 나왔으면 
        if(op1<min) min=result;
        if(op1>max) max=result;
        return;
    }

    for(int i=0;i<4;i++){
        if(operator[i]>0){
            operate(i, n+1, result, operator);
        }
    }

}

int main(){

    scanf("%d", &k);
    num = (int *)malloc(sizeof(int)*k);
    int operator[4];

    for(int i=0;i<k;i++){
        scanf("%d", &num[i]);
    }
    for(int i=0;i<4;i++){
        scanf("%d", &operator[i]);
    }

    //연산자 갯수가 0보다 크면 각 연산자마다 재귀함수로 보낸다. 
    for(int i=0;i<4;i++){
        if(operator[i]<1) continue;
        operate(i, 1, num[0], operator);
        // for(int j=0;j<4;j++){
        //     printf("%d  ", operator[j]);
        // }
    }
    printf("%d %d", max, min);
    

    return 0;
}