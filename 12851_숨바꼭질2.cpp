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
    int minTimes=0;
    int ways=0;

    while(!q.empty()){
        
        int n = q.front().first;
        int times = q.front().second;
        q.pop();

        visited[n]=1; // 매우 중요 !!
        // 넣을 때 방문체크를 해주는게 아니라 뺄때 방문체크를 해주는 이유는 
        // 넣을 때 한 번 visited[k]=1로 바꾸면 더 이상 그쪽으로 못온다. 그래서 way가 항상 1밖에 못됨. 
        // 뺄때 방문체크를 하면 같은 level인 애들에 대해서는 중복이 있을 수 있지만 그 점을 이용한 것
        
        if(n==K){
            if(minTimes==0){ // 처음 정답이 나왔을때
                minTimes=times;
                ways++;
            }
            else if(minTimes==times){ // 또 나왔을떄
                ways++;
            }
        }

        if(n+1<MAX && !visited[n+1]){
            q.push(make_pair(n+1, times+1));
        }
        if(n-1>=0 && !visited[n-1]){
            q.push(make_pair(n-1, times+1));
        }
        if(n*2<MAX && !visited[n*2]){
            q.push(make_pair(n*2, times+1));
        }
        
    }
    cout << minTimes<<"\n";
    cout << ways;

}

int main(){

    cin >>N>>K;
    memset(visited, 0, sizeof(visited));
    
    bfs(N);

    return 0;
}