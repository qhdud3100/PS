#include <iostream>
#include <queue>
using namespace std;

//! 틀렸습니다! 테스트케이스 통과 못함.

/*
    빨간 돌과 파란 돌이 겹치지 않게 하기 위해서
    
    방식 1: 기울일때 더 아래에 있는 돌을 먼저 기울이기

    방식 2: 빨간 돌과 파란 돌을 개별적으로 움직인 뒤 위치가 같은 것에 대해 따로 검사하여 처리해줌
    거리가 멀면 한칸 덜 이동한다. 이런식으로 ㅋㅋㅋㅋ??
    
    Let's try first one.
*/

typedef struct Position{
    int redX;
    int redY;
    int blueX;
    int blueY;
    int depth;
} Position;

int N, M;
int map[11][11];
int redX, redY, blueX, blueY, holeX, holeY;
int dx[4]={1,-1,0,0}; //오른쪽, 왼쪽, 위, 아래
int dy[4]={0,0,-1,1};
int visited[11][11][11][11];// red와 blue의 각각 x,y좌표의 방문여부를 체크. 이전에 둘 다 왔던 위치면 이동하지 않기.
queue<Position> que;
int result;


void print_map(Position cur){

    cout << "\n";
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==cur.blueY && j==cur.blueX) cout << "B" << " ";
            else if(i==cur.redY && j==cur.redX) cout << "R" << " ";
            else cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void red_first_lean(Position cur, int dir){

    Position next;
    next.redX = cur.redX;
    next.redY = cur.redY;
    next.blueX = cur.blueX;
    next.blueY = cur.blueY;
    next.depth = cur.depth + 1;    

    while(1){ // 빨간색먼저 움직이기
        if(map[next.redY+dy[dir]][next.redX+dx[dir]]==1 || (next.blueY==next.redY+dy[dir] && next.blueX==next.redX+dx[dir])) break; // 벽이거나 파란공있으면 그만가기
        next.redY = next.redY + dy[dir];
        next.redX = next.redX + dx[dir];

        if(next.redY == holeY && next.redX == holeX){ //빨간 공이 구멍에 들어가면
            result = next.depth; // 이렇게 하는 이유: 파란색 공도 구멍 통과하면 실패처리해야함.
            break;
        }
    }

    while(1){ // 파란색 움직이기
        if(map[next.blueY+dy[dir]][next.blueX+dx[dir]]==1 || (next.redY==next.blueY+dy[dir] && next.redX==next.blueX+dx[dir])) break; // 벽이거나 파란공있으면 그만가기
        next.blueY = next.blueY + dy[dir];
        next.blueX = next.blueX + dx[dir];

        if(next.blueY == holeY && next.blueX == holeX){ //파란 공이 구멍에 들어가면
            result = 0; // 그냥 아예 0으로 만들어버리고 이 가능성을 아예 없애버림
            return;
        }
    }

    if(result > 0){
        cout << result<<"\n";
        exit(0);
    }

    if(!visited[next.redY][next.redX][next.blueY][next.blueX]){
        que.push(next);
        visited[next.redY][next.redX][next.blueY][next.blueX]=1;
    }

}

void blue_first_lean(Position cur, int dir){

    Position next;
    next.redX = cur.redX;
    next.redY = cur.redY;
    next.blueX = cur.blueX;
    next.blueY = cur.blueY;
    next.depth = cur.depth + 1;
    

    while(1){ // 파란색 먼저 움직이기
        if(map[next.blueY+dy[dir]][next.blueX+dx[dir]]==1 || (cur.redY==next.blueY+dy[dir] && cur.redX==next.blueX+dx[dir])) break; // 벽이거나 파란공있으면 그만가기
        next.blueY = next.blueY + dy[dir];
        next.blueX = next.blueX + dx[dir];

        if(next.blueY == holeY && next.blueX == holeX){ //파란 공이 구멍에 들어가면
            result = 0; // 그냥 아예 0으로 만들어버리고 이 가능성을 아예 없애버림
            return;
        }
    }

    while(1){ // 빨간색 움직이기
        if(map[next.redY+dy[dir]][next.redX+dx[dir]]==1 || (cur.blueY==next.redY+dy[dir] && cur.blueX==next.redX+dx[dir])) break; // 벽이거나 파란공있으면 그만가기
        next.redY = next.redY + dy[dir];
        next.redX = next.redX + dx[dir];

        if(next.redY == holeY && next.redX == holeX){ //빨간 공이 구멍에 들어가면
            result = next.depth; // 이렇게 하는 이유: 파란색 공도 구멍 통과하면 실패처리해야함.
            break;
        }
    }

    if(result > 0){
        cout << result<<"\n";
        exit(0);
    }

    if(!visited[next.redY][next.redX][next.blueY][next.blueX]){
        que.push(next);
        visited[next.redY][next.redX][next.blueY][next.blueX]=1;
    }


}

void bfs(){ 

    Position p = {redX, redY, blueX, blueY, 0};

    que.push(p);

    while(!que.empty()){
        Position cur = que.front(); que.pop();

        // print_map(cur);

        if(cur.depth>10){
            cout << -1;
            return ;
        }

        if(cur.redX>cur.blueX){ //오른쪽으로 기울이기 
            red_first_lean(cur, 0);
        }else{
            blue_first_lean(cur, 0);
        }

        if(cur.redX<cur.blueX){ //왼쪽으로 기울이기 
            red_first_lean(cur, 1);
        }else{
            blue_first_lean(cur, 1);
        }
        
        if(cur.redY<cur.blueY){ //위쪽으로 기울이기 
            red_first_lean(cur, 2);
        }else{
            blue_first_lean(cur, 2);
        }
        
        if(cur.redY>cur.blueY){ //아래쪽으로 기울이기 
            red_first_lean(cur, 3);
        }else{
            blue_first_lean(cur, 3);
        }
        
    }
}

int main(){
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        string line;
        cin >> line;
        for(int j=0;j<M;j++){
            if(line[j]=='#') map[i][j+1]=1;
            else if(line[j]=='.') map[i][j+1]=0;
            else if(line[j]=='R'){
                redX = j+1;
                redY = i;
            }else if(line[j]=='B'){
                blueX = j+1;
                blueY = i;
            }else if(line[j]=='O'){
                holeX = j+1;
                holeY = i;
            }
        }
    }

    bfs();

    return 0;
}
