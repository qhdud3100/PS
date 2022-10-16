#include <iostream>
#include <algorithm>

using namespace std;
int N,S,M;
int change[55];
bool cache[55][1010];
int Max=-1;

void DP(){

    cache[0][S]=true;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(cache[i][j]){
                int left = j-change[i+1];
                int right = j+change[i+1];
                if(left>=0) cache[i+1][left]=true;
                if(right<=M) cache[i+1][right]=true;
            }
            if(i==N && cache[i][j]){
                Max = max(Max, j);
            }
        }
    }
    cout << Max;
}

int main(){

    cin >> N>>S>>M;
    for(int i=1;i<=N;i++) cin >> change[i];
    DP();

    return 0;
}