#include <iostream>
#include <queue>

using namespace std;

long A, B;

int bfs(long startNum){

    queue<pair<long , int> >q; //현재 숫자, 연산숫자
    q.push(make_pair(startNum, 1));
    
    while(!q.empty()){

        long n = q.front().first;
        int times = q.front().second;
        q.pop();

        if(n==B) return times;

        if(n*2<=B) q.push(make_pair(n*2, times+1));
        if(n*10+1<=B) q.push(make_pair(n*10+1, times+1));
        
    }
    return -1;
}

int main(){

    cin >>A >>B;
    int times = bfs(A);
    cout << times;
    return 0;
}