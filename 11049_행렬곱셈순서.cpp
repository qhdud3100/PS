#include <iostream>
#include <vector>
#include <climits>

using namespace std;

    int N;
    int r, c;
    int cache[501][501]; //직관적인 변수이름 짓기. 과거의 기록 저장
    int matrix_size[501][2]; // row, column


void dp(){

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++){
            if(i==j) cache[i][j]=0;
            else cache[i][j]=INT_MAX;
        }
    }
    

    for(int step=1;step<=N-1;step++){
        for(int start=1;start+step<=N;start++){
            int end = start+step; // 2번 이상 등장하면 미리 변수로 만들어두기
            for(int k=start; k<end; k++){
                cache[start][end] = min(cache[start][end], cache[start][k]+cache[k+1][end]+ matrix_size[start][0]*matrix_size[k][1]*matrix_size[end][1]);
            }
        }
    }

    cout << cache[1][N];

}

int main(){

    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> r >> c;
        matrix_size[i][0]=r;
        matrix_size[i][1]=c;
    }
    dp();

    return 0;
}