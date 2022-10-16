#include <iostream>
#include <cstring>

using namespace std;

/*
    봐도봐도 스스로는 못풀겠는 문제 
    비슷한 문제: 11052_카드 구매하기
*/

int T;
int cache[12];

int addWays(int n){

    memset(cache, 0, sizeof(cache));
    cache[1]=1;
    cache[2]=2;
    cache[3]=4;
    for(int i=4;i<=n;i++) cache[i] = cache[i-1]+cache[i-2]+cache[i-3];

    return cache[n];
}

int main(){
    int n;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        cout << addWays(n)<<"\n";
    }

}