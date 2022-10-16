#include<iostream>

using namespace std;

int N;
int cost[1500002];
int value[1500002];
int cache[1500002];


void DP(){

    for(int i=1;i<=N;i++){
        int payday = i-1+cost[i];
        if(payday <= N) cache[payday] = max(cache[payday], cache[i-1]+value[i]);
        cache[i] = max(cache[i],cache[i-1]);
    }
    cout << cache[N];
}


int main(){

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> cost[i] >> value[i];
    }
    DP();

    return 0;
}
