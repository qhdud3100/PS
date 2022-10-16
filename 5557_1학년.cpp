#include <iostream>

using namespace std;

int N;
int operand[101];
long cache[101][21]; //i번째 operand까지 고려하여 연산을 했을때 결과값이 j이 나오는 방법의 갯수
int answer;

void dp(){

    cache[1][operand[1]]=1;
    for(int i=1;i<N-1;i++){
        for(int j=0;j<=20;j++){
            if(!cache[i][j]) continue;
            int left = j-operand[i+1];
            int right = j+operand[i+1];
            if(left>=0) cache[i+1][left] += cache[i][j];
            if(right<=20) cache[i+1][right] += cache[i][j];
        }
    }

    cout << cache[N-1][answer];

}

int main(){

    cin >> N;
    for(int i=1;i<N;i++) cin >> operand[i];
    cin >> answer;
    dp();

    return 0;
}