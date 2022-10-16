#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int visited[1001];
int visited2[1001];
priority_queue<int, vector<int>, greater<int> > pq[1001];
priority_queue<int, vector<int>, greater<int> > pq2[1001];

// Q. 사용하면 더러워지는 표가 두번 필요할때, 두개를 만들어야할까? 더 좋은 방법은?

void dfs(int x){
    cout<<x<<" ";
    visited[x]=1;
    while(!pq[x].empty()){
        int y = pq[x].top();
        pq[x].pop();
        if(!visited[y]) dfs(y);
    }
}

void bfs(int s){

    queue<int> q;
    q.push(s);
    visited2[s]=1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        while(!pq2[x].empty()){
            int y = pq2[x].top();
            pq2[x].pop();
            if(!visited2[y]) {
                q.push(y);
                visited2[y]=1;
            }
            
        }
    }


}

int main(){

    cin>>N>>M>>V;

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        pq[a].push(b);
        pq[b].push(a);
        pq2[a].push(b);
        pq2[b].push(a);
    }

    dfs(V);
    cout<<"\n";
    bfs(V);

    return 0;
}