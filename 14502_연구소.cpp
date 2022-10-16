#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] ={-1,0,0,1};
int dy[4] ={0,-1,1,0};
int map[9][9];
int copied_map[9][9];
int visited[9][9];
int MaxSafe=0;
int safeCount;

int spreading(){
    int visited[10][10];
    int zeroCount=0;

    for(int i=0;i<=8;i++){
        for(int j=0;j<=8;j++){
            visited[i][j]=0;
        }
    }

    queue<pair<int, int> > q;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(copied_map[i][j]==2) {
                visited[i][j]=1;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(copied_map[ny][nx]!=0) {continue;}
            if(visited[ny][nx]) {continue;}
            if(nx<1 || ny<1 || ny>N || nx>M) {continue;}

            visited[ny][nx]=true;
            copied_map[ny][nx]=2;
            q.push(make_pair(ny, nx));
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(copied_map[i][j]==0) zeroCount++;
        }
    }
    
    return zeroCount;
}

void dfs(int times, int si, int sj){

    if(times>=3){

        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                copied_map[i][j] = map[i][j];
            }
        }
        safeCount = spreading();
        MaxSafe = max(safeCount, MaxSafe);
        return;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i==1 && j ==1){ //이걸로 조합 구현 ㅋㅋㅋ
                i = si;
                j = sj;
            }
            if(map[i][j]==0){
                map[i][j]=1;
                dfs(times+1, i, j);
                map[i][j]=0;
            }
        }
    }

}

int main(){

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }

    dfs(0, 1,1);
    cout << MaxSafe;
    return 0;
}