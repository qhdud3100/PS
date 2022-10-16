#include <iostream>
#include<algorithm>
#include <queue>

using namespace std;

int N, M, k;
int map[102][102];
int visited[102][102];
int dx[4] ={-1,0,0,1};
int dy[4] ={0,-1,1,0};

//한 덩어리마다 한 번의 bfs를 거침
int bfs(int y, int x){

    
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visited[y][x]=1;
    int count=1;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<1 || nx>M || ny<1 || ny>N) continue;
            if(map[ny][nx] && !visited[ny][nx]){
                q.push(make_pair(ny, nx));
                visited[ny][nx]=1;
                count++;
            }
        }

    }

    return count;
}

int main(){
    cin >> N>>M>>k;
    int maxCount=0;

    for(int i=0;i<k;i++){
        int x,y;
        cin>>y>>x;
        map[y][x]=1;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(!visited[i][j] && map[i][j]) {
                maxCount = max(maxCount, bfs(i,j));
            }
        }
    }

    cout << maxCount;
    return 0;
}