#include <iostream>
#include <queue>


using namespace std;

int visited[100][100];
int maze[100][100];
int N,M;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            visited[i][j]=0;
        }
    }
}

void bfs(int sx, int sy){ //startx, startY

    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(sx,sy), 1));
    visited[sy][sx]=1;

    while(!q.empty()){

        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        q.pop();

        if(x==M-1 && y==N-1){
            cout<<count;
        }

        for(int i=0;i<4;i++){
            int nx = x+dx[i]; //next X . 변수가 두 번 이상 등장하면 반드시 변수로 만드기
            int ny = y+dy[i];
            if(nx<0 || nx>=M || ny<0 || ny>=N ) continue;
            if(!visited[ny][nx] && maze[ny][nx]){ //길이고 && 방문을 안했으면
                q.push(make_pair(make_pair(nx, ny), count+1));
                visited[ny][nx]=1;
            }
        }
    }
}

int main(){

    int tmp;
    cin >> N >> M;

    init();

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs(0,0);
    

    return 0;
}