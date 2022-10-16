#include <iostream>
#include <deque>
#include <cstring>

//////////* 좀 더 세련되게 구현한 코드 *///////////
/*

감을 되찾고싶을 때 다시 풀어보면 좋을 것 같은 문제이다. ^^

*/

using namespace std;
deque<int> gear[5];
bool visited[5]={false,};
int K;
int sum=0;

void revolve_one(int what, int direction){ 
    if(direction==-1){ //-1일때는 반시계방향
        int tmp = gear[what].front();
        gear[what].pop_front();
        gear[what].push_back(tmp);
    }else{ //1일때는 시계방향
        int tmp = gear[what].back();
        gear[what].pop_back();
        gear[what].push_front(tmp);
    }

}

void print_gears(){ 
    for(int i=1;i<=4;i++){
        for(int j=0;j<8;j++){
            cout << gear[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void revolve_all(int start, int direction){ 

    visited[start]=true;

    // 왼쪽으로 보내기
    if(start-1>=1){
        if(!visited[start-1] && gear[start-1][2] != gear[start][6]){
            revolve_all(start-1, -direction);
        }
    }
    // 오른쪽으로 보내기
    if(start+1<=4){
        if(!visited[start+1] && gear[start][2] != gear[start+1][6]){
            revolve_all(start+1, -direction);
        }
    }

    revolve_one(start, direction);

}

int main(){
    for(int i=1;i<=4;i++){ //1번 톱니바퀴부터 입력
        string line;
        cin >> line;
        for(int j=0;j<8;j++){
            gear[i].push_back(line[j]-'0');
        }
    }

    cin >> K;
    int start[K], direction[K];
    for(int i=0;i<K;i++){ 
        cin >> start[i];
        cin >> direction[i];
    }
    for(int i=0;i<K;i++){
        memset(visited, false, 5);
        revolve_all(start[i], direction[i]);
    }
    sum = gear[1][0] + gear[2][0]*2 + gear[3][0]*4 + gear[4][0]*8;
    cout << sum;
    return 0;

}