#include <iostream>
#include <queue>
using namespace std;

/*
    insight 1: 백조들이 만날 수 있을지 검사하기 위해 백조에 대한 bfs를 돌린다.
    insight 2: 매 melt마다 일반적인 bfs를 하는 것이 아니라 
    -> 방금 녹은 것에 대해서만 bfs를 돌린다. 딱 녹을 때 큐에 넣고 그 물이 다음 방향으로 영향을 줄때 뺀다. 
    insight 3: 큐에 x,y,depth 세 개를 넣는 방법은 메모리 초과가 발생한다. =
    -> 두개의 큐를 만들어서 nx, ny는 다음 큐에 넣고 한 번 탐색 끝낸 후 다음 큐를 큐에게 넘긴다. 
    insight 4: swan에 대해 bfs를 돌릴때도 계속 처음부터 다시 돌리면 시간 초과가 발생한다. 
    -> 이것도 방금 녹은 부분에 대해서만 돌린다. 
    
*/

int R, C;
int visited[1501][1501];
int map[1501][1501];
int day_visited[1501];
queue<pair<pair<int, int>, int> > ice_que;
queue<pair<int, int> > swan_que;
int startX, startY, destX, destY, flag;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void print_map(){

    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void reset_visited(){

 for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            visited[i][j]=0;
        }
    }

}

int possible(){

    // print_map();
    reset_visited();

    swan_que.push(make_pair(startY, startX));
    visited[startY][startX]=1;

    while(!swan_que.empty()){
        int cy = swan_que.front().first;
        int cx = swan_que.front().second;
        swan_que.pop();
        // cout << cy << ", "<< cx << "\n";

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny<1 || nx<1 || ny>R || nx>C || visited[ny][nx] || map[ny][nx]==1) continue; //얼음이면 못지나감

            swan_que.push(make_pair(ny, nx));
            visited[ny][nx]=1;

            if(ny==destY && nx==destX) return 1;
        }
    }

    return 0;
}

void bfs(){

    while(!ice_que.empty()){
        int cy = ice_que.front().first.first;
        int cx = ice_que.front().first.second;
        int depth = ice_que.front().second;
        ice_que.pop();

        if(day_visited[depth]==0){ // day가 바뀔때마다 한번씩만 검사한다. 
            day_visited[depth]=1;
            if(possible()){
                cout << depth; 
                return;
            }
        }

        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(map[ny][nx]==1)//얼음이면

            map[ny][nx]=0; //물로 만들기
            ice_que.push(make_pair(make_pair(ny, nx), depth+1));
        }

        
    }


}

void input(){

    char tmp;
    cin >> R >> C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> tmp;
            if(tmp=='.') {
                map[i][j]=0; //물은 0
                ice_que.push(make_pair(make_pair(i, j), 0)); // y좌표, x좌표, depth
            }
            if(tmp=='X') map[i][j]=1; //얼음은 1
            if(tmp=='L'&& !flag){ //처음 나왔으면 start에 저장
                startY=i;
                startX=j;
                flag= 1;
            }
            if(tmp=='L'&& flag){ //두번째로 나왔으면 dest에 저장
                destY=i;
                destX=j;
            }
        }
    }

}


int main(){
    
    
    input();
    bfs();

    return 0;
}