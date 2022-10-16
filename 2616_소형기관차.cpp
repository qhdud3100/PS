#include <iostream>

using namespace std;

int n, Max;
int cache[4][50001];
int person[50001];

void dp(){

    for(int i=1;i<=3;i++){
        for(int j=i*Max;j<=n;j++){
            cache[i][j] = max(cache[i-1][j-Max] + person[j]-person[j-Max], cache[i][j-1]);
        }
    }

    cout << cache[3][n];
}

int main(){

    cin >> n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        person[i] = person[i-1] + tmp;
    }
    
    cin >> Max;
    dp();

    return 0;
}
