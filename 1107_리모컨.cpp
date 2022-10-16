#include <iostream>
#include <cstring>

using namespace std;

int N;
bool usable[10];
int minPressed;

void dfs(int times, int num){
    if(times>6) return;
    if(times!=0){
        int press = abs(N-num)+times;
        minPressed = min(minPressed, press);
    }


    for(int i=0;i<=9;i++){
        if(!usable[i]) continue;
        dfs(times+1, num*10 + i);
    }
}

int main(){

    int brokenCount;
    cin >> N;
    cin >> brokenCount;
    minPressed = abs(N-100);

    memset(usable, true, 10*sizeof(bool));

    for(int i=0;i<brokenCount;i++){
        int broken;
        cin >> broken;
        usable[broken]=false;
    }
    
    dfs(0,0);
    cout << minPressed;

    return 0;
}