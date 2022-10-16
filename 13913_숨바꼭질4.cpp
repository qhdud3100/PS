#include <iostream>
#include <queue>
#include<cstring>
#include<stack>
#define MAX 100001
using namespace std;

int N, K;
int visited[MAX];
int parent[MAX]; //내 부모를 저장해두는 배열

void bfs(int startX){

    queue<pair<int, int> >q;
    q.push(make_pair(startX, 0)); //현재숫자, 연산횟수
    visited[startX]=1;

    while(!q.empty()){
        
        
        int n = q.front().first;
        int times = q.front().second;
        q.pop();
        
        if(n==K){
            cout << times<<"\n";

            stack<int> s;
            s.push(n);
            int prev = parent[n];
            for(int i=0;i<times;i++){
                s.push(prev);
                prev = parent[prev];
            }
            while(!s.empty()){
                cout << s.top()<<" ";
                s.pop();
            }

            return;
        }
        if(n+1<MAX && !visited[n+1]){
            q.push(make_pair(n+1, times+1));
            visited[n+1]=1;
            parent[n+1]=n;
        }
        if(n-1>=0 && !visited[n-1]){
            q.push(make_pair(n-1, times+1));
            visited[n-1]=1;
            parent[n-1]=n;
        }
        if(n*2<MAX && !visited[n*2]){
            q.push(make_pair(n*2, times+1));
            visited[n*2]=1;
            parent[n*2]=n;
        }
        
    }

}

int main(){

    cin >>N>>K;
    memset(visited, 0, sizeof(visited));
    
    bfs(N);

    return 0;
}