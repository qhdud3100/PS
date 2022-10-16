#include <iostream>
using namespace std;

// 아이디어:인터넷 참고 
// 올라가려면 특정 count를 쌓아뒀어야하고 내려갈때는 특정 값을 미리 까준다. 가불하는 것처럼

int N, L;
int wayCount(int map[][101]){

    int success=0;
    int count;
    
    // 가로로 조사 
    for(int i=1;i<=N;i++){
        count =1;
        for(int j=1;j<=N;j++){
            // cout << i <<", " << j << "\n";
            if(j==1) continue;
            if(abs(map[i][j-1]-map[i][j])>1) {break;}

            if(map[i][j-1] -1 == map[i][j]){ //내려가는 경우
                if(count<0) {break;} // 내려감 -> 내려감 실패
                count = -L;
                count++;
            }else if(map[i][j-1] +1 == map[i][j]){ //올라가는 경우
                if(count<L) {break;}
                count = 1;
            }else{ //평지
                count++;
            }
            if(j==N && count>=0) success++;
        }
    }
    return success;
}

int main(){
    
    cin >> N >> L;
    int map[101][101];
    int reverseMap[101][101];
    int slope=0;
    int successSum=0;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
            reverseMap[j][i] = map[i][j];
        }
    }
    successSum = wayCount(map)+wayCount(reverseMap);
    
    cout << successSum;
    return 0;
}