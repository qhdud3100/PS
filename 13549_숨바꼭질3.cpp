#include <iostream>
#include <queue>
#include<cstring>

#define MAX 100001
using namespace std;

int N, K;
int visited[MAX];

void bfs(int startX){

    queue<pair<int, int> >q;
    q.push(make_pair(startX, 0)); //현재숫자, 연산횟수
    visited[startX]=1;
    int minCost=MAX;

    while(!q.empty()){
        
        
        int n = q.front().first;
        int times = q.front().second;
        q.pop();
        
        if(n==K){
            cout << times;
            break;
        }
        if(n*2<MAX && !visited[n*2]){ // 중요 : 여기서 이걸 먼저해줘야하는이유 
            // 결과가 이미 이전에 나와서 visited가 1로 바껴버려서 더 짧은 경로가 나왔을때 못감
            // 반례 : n=1 , k=2 
            q.push(make_pair(n*2, times));
            visited[n*2]=1;
        }
        if(n-1>=0 && !visited[n-1]){
            q.push(make_pair(n-1, times+1));
            visited[n-1]=1;
        }
        if(n+1<MAX && !visited[n+1]){
            q.push(make_pair(n+1, times+1));
            visited[n+1]=1;
        }

        
    }

}

int main(){

    cin >>N>>K;
    memset(visited, 0, sizeof(visited));
    
    bfs(N);

    return 0;
}