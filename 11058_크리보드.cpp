#include <iostream>
#include <algorithm>

using namespace std;

long cache[101];

void dp(int N){
    
    cache[1]=1;
    cache[2]=2;
    cache[3]=3;
    for(int i=1;i<=N;i++){
        if(i+1<=100) cache[i+1]=max(cache[i+1], cache[i]+1); // 1을 누르는 경우
        if(i+3<=100) cache[i+3]=max(cache[i+3], cache[i]*2); // 2,3,4를 누르는 경우
        if(i+4<=100) cache[i+4]=max(cache[i+4], cache[i]*3); // 2,3,4,4를 누르는 경우
        if(i+5<=100) cache[i+5]=max(cache[i+5], cache[i]*4); // 2,3,4,4,4를 누르는 경우
        if(i+6<=100) cache[i+6]=max(cache[i+6], cache[i]*5); // 2,3,4,4,4,4를 누르는 경우
    }
    cout << cache[N];

}

int main(){

    int N;
    cin >> N;
    dp(N);

    return 0;
}