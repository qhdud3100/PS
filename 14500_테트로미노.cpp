#include <iostream>
using namespace std;

int N, M;
int map[510][510];
bool visited[510][510];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int Max=0;

void dfs(int depth, int y, int x, int sum){
    
    if(depth==4){
        Max = max(Max, sum);

        // if(Max > sum) return;
        // cout << sum<<"\n";
        // for(int i=1;i<=N;i++){
        //     for(int j=1;j<=M;j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout <<  "\n";
        return ;
    }
    if(depth==2){ // ㅗ 모양
        for(int n=0;n<4;n++){
            int ny = y + dy[n];
            int nx = x + dx[n];
            if(nx<1 || nx>M || ny<1 || ny>N) continue;
            if(visited[ny][nx]==false) continue;
            
            int ly = y + dy[(n+3)%4]; // 왼쪽에 있는 블럭
            int lx = x + dx[(n+3)%4];
            int ry = y + dy[(n+1)%4]; // 오른쪽에 있는 블럭
            int rx = x + dx[(n+1)%4];
            if(lx<1 || lx>M || ly<1 || ly>N) continue;
            if(rx<1 || rx>M || ry<1 || ry>N) continue; //왼쪽, 오른쪽 튀어나온 블럭이 범위를 넘어가면 패스
            dfs(4, 0,0, sum + map[ly][lx] + map[ry][rx]);
        }
    }

    for(int n=0;n<4;n++){
        int ny = y + dy[n];
        int nx = x + dx[n];

        if(nx<1 || nx>M || ny<1 || ny>N) continue;
        if(visited[ny][nx]==true) continue;

        visited[ny][nx]=true;
        dfs(depth+1, ny, nx, sum+map[ny][nx]);
        visited[ny][nx]=false;
    }
}

int main(){

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            visited[i][j]=true;
            dfs(1,i,j,map[i][j]);
            visited[i][j]=false;
        }
    }
    cout << Max;
    

    return 0;
}