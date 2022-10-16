#include <iostream>

using namespace std;


//* 다시 풀어봤는데 바로 생각이 안남

int numbers[21];
int S, N;
int cnt=0;

void DFS(int times, int sum){

    // 마지막까지 다 돌면 종료 
    if(times==N)return;
    // sum == S면 count++
    if(sum + numbers[times]==S) {
        cnt++;
    }
    // DFS(times+1, sum+numbers[times])
    DFS(times+1, sum+numbers[times]);
    // DFS(times+1, sum)
    DFS(times+1, sum);

}

int main(){

    cin >> N>>S;
    for(int i=0;i<N;i++){
        cin >> numbers[i];
    }

    //재귀함수로 들어간다.
    DFS(0, 0);
    cout << cnt;

    return 0;
}