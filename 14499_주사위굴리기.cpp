#include <iostream>

using namespace std;

int N, M, K;
int map[21][21];
int dice[7]={0,};
int curX, curY;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};

/*
    3d인 주사위를 어떻게 구현할까?
    배열을 하나 만들어서 배열의 값을 바꿈으로서 주사위의 회전을 구현한다. 
*/

void rotate(int dir){
    int tmp;
    switch(dir){
        case 1:
            tmp = dice[3]; dice[3]=dice[1]; dice[1]=dice[4]; dice[4]=dice[6]; dice[6]=tmp;
            break;
        case 2:
            tmp = dice[3]; dice[3]=dice[6]; dice[6]=dice[4]; dice[4]=dice[1]; dice[1]=tmp;
            break;
        case 3:
            tmp = dice[1]; dice[1]=dice[5]; dice[5]=dice[6]; dice[6]=dice[2]; dice[2]=tmp;
            break;
        case 4:
            tmp = dice[1]; dice[1]=dice[2]; dice[2]=dice[6]; dice[6]=dice[5]; dice[5]=tmp;
            break;
    }
}

void update(){
    if (map[curY][curX] == 0){
        map[curY][curX] = dice[6];
    }else{
        dice[6]= map[curY][curX];
        map[curY][curX] = 0;
    }
}

void print_dice(){
    cout << "  " << dice[2] << "  \n";
    cout << dice[4] << " " << dice[1] << " " << dice[3] << "\n";
    cout << "  " << dice[5] << "\n";
    cout << "  " << dice[6]; 
    cout << "\n\n";
}

int main(){

    int dir;
    cin >> N >> M >> curY >> curX >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0;i<K;i++){
        cin >> dir;
        if(curX+dx[dir]<0 || curX+dx[dir]>M-1 || curY+dy[dir]<0 || curY+dy[dir]>N-1) continue;
        curX=curX+dx[dir]; //현재위치 갱신
        curY=curY+dy[dir]; 
        rotate(dir); //주사위 돌리기
        update(); // 주사위값, 맵 변경하기
        cout << dice[1]<<"\n";
    }
    
    return 0;
}