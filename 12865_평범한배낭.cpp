#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int weight[101];
int value[101];
int cache[101][100001];


void dp(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(j-weight[i]>=0)cache[i][j] = max(cache[i-1][j], cache[i-1][j-weight[i]]+value[i]);
            else cache[i][j] = cache[i-1][j];
        }
    }
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=K;j++){
    //         cout << cache[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }
    cout << cache[N][K];

}

int main(){

    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> weight[i] >> value[i];
    }

    dp();

}