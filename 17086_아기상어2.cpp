#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[51][51];
int visited[51][51];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,-1,-1,-1,0,1,1,1};
int N,M, tmp, maxDist=0;

int Bfs(int sy, int sx){

    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int> >q;
    q.push(make_pair(make_pair(sx, sy), 0));
    visited[sy][sx]=1;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int distance = q.front().second;
        q.pop();
        
        if(map[y][x]){
            //cout << y << ", " << x << " : "<< distance<<"\n";
            return distance;
        }
        
        for(int i=0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //cout << " nx , ny : " << ny << ", " << nx << ", : "<<visited[ny][nx]<< "\n";
            if(!visited[ny][nx] && nx>=0 && nx<M && ny>=0 && ny<N){
                q.push(make_pair(make_pair(nx, ny), distance+1));
                visited[ny][nx]=1;
            }
        }
    }
    return 0;
}

int main(){

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0) {
                maxDist = max(maxDist, Bfs(i, j));
            }
        }
    }

    cout << maxDist;
    return 0;
}
