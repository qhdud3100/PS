#include <iostream>
#include <stdio.h>

using namespace std;
 
int N, M, Max=0;
int numbers[51][51];

int main(){

    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
             scanf("%1d",&numbers[i][j]);
        }
    }
    int minLength = min(N,M);
    // 크기는 1부터 minLength까지
    for(int size=1;size<=minLength;size++){
        
        // 윗시작점 i=1부터 i+크기-1가 minLength까지
        for(int i=1;i+size-1<=N;i++){
            //왼쪽시작점 i=1부터 i+크기-1가 minLength까지 
            for(int j=1;j+size-1<=M;j++){
                // 네방향 모두 같으면 크기*크기를 max값으로 설정
                if(numbers[i][j]==numbers[i][j+size-1] && numbers[i][j]==numbers[i+size-1][j] && numbers[i][j]==numbers[i+size-1][j+size-1]){
                    Max = max(Max, size*size);
                }
                //cout << i<< ", " << j << " -> " << i+size-1 << ", " << j+size-1 << "\n";
            }
            //cout << "\n";
        }
        //cout << "Max : " << Max;
    }


    cout << Max;



    return 0;
}