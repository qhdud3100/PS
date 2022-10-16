#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

long MAX_NUM=1000000000000;
int N;
long cache[1001];
char tile[1001];

void dp(){
    
    cache[1]=0;

    for(int i=1;i<=N;i++){

        if(cache[i]==MAX_NUM) continue;
        for(int j=i+1;j<=N;j++){
            if((tile[i]=='B' && tile[j]=='O') || (tile[i]=='O' && tile[j]=='J') || (tile[i]=='J' && tile[j]=='B')){
                cache[j] = min(cache[j], cache[i]+(j-i)*(j-i));
            }
        }
    }    
    //for(int i=1;i<=N;i++) cout << cache[i]<<"\n";
    if(cache[N]>=MAX_NUM) cout << -1;
    else cout << cache[N];


}

int main(){

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> tile[i];
    }
    memset(cache, MAX_NUM/3, sizeof(cache));
    dp();

    return 0;
}