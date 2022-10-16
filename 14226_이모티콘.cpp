#include <iostream>
#include <queue>
#include<cstring>
using namespace std;

int main(){

    int S;
    cin >> S;

    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(0,1), 0)); // 클립보드, 현재값, 시간
    int visited[1001][1001];
    memset(visited, 0, sizeof(int) * 1001);

    while(!q.empty()){

        int clip = q.front().first.first;
        int n = q.front().first.second;
        int times = q.front().second;
        q.pop();

        if(n==S){
            cout<< times;
            return 0;
        }
        //cout << clip <<", "<<n <<",  "<<times<<"\n";

        if(!visited[n][n]){
            q.push(make_pair(make_pair(n, n), times+1)); // 클립보드에 복사
            visited[n][n]=1;
        }
        if(!visited[clip][n+clip] && n+clip<=1000){  
            q.push(make_pair(make_pair(clip, n+clip), times+1)); // 붙여넣기
            visited[clip][n+clip]=1;
        }
        if(!visited[clip][n-1] && n-1>0){
            q.push(make_pair(make_pair(clip, n-1), times+1)); // 1개 삭제
            visited[clip][n-1]=1;
        }
    }
    

    return 0;
}