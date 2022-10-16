#include <iostream>
#include <vector>

using namespace std;

int cnt=0;
int visited[101];
vector<int> connected[101];
int N, k;


void find(int n);
int main(){

    int a, b;

    scanf("%d", &N);
    scanf("%d", &k);

    //입력
    for(int i=0;i<k;i++){
        scanf("%d", &a);
        scanf("%d", &b);
        connected[a].push_back(b);
        connected[b].push_back(a);
    }
    
    find(1);
    printf("%d", cnt);

    return 0;
}

void find(int n){


    visited[n]=true;
    for(int i=0;i<connected[n].size();i++){
        int next = connected[n].at(i);

        if(!visited[next]) {
            find(next);
            cnt++;
        }
    }
}