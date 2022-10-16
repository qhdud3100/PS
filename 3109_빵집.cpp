#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>  // sorting 류
#include <limits.h> // INT_MAX
#include <string>

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }

int R, C;
int dy[3]={-1,0,1};
char tmp;
int map[10001][501];
int visited[10001][501];
int pipeline=0;
int is_success[10001];


/*-------------------------------------------------------------------------

    아이디어: 인터넷 참고
    구현: EZ
    char는 한개씩 입력받을때 scanf("%1c") 안해도된다. 어차피 cin해도 한개만 받아올 수 있음.

 -------------------------------------------------------------------------*/

void print_map(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<< map[i][j]<< " "; 
        }
        cout <<"\n";
    }
    cout <<"\n\n";
}

void DFS(int sy, int y, int x){

    visited[y][x]=1;

    if(x==C-1){
        pipeline++;
        is_success[sy]=1;
        // print_map();
        return;
    }
    for(int i=0;i<3;i++){
        int nx = x+1;
        int ny = y + dy[i];

        if(ny>=0 && ny<R && !visited[ny][nx] && map[ny][nx]!=1 && !is_success[sy])
            DFS(sy, ny, nx);
    }

}

int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3




    cin >> R >> C;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>> tmp;
            if(tmp=='.'){
                map[i][j]=0; //지나갈 수 있음
            }else if(tmp=='x'){
                map[i][j]=1; //지나갈 수 없음
            }
        }
    }

    for(int i=0;i<R;i++){
        DFS(i, i, 0); //starty, y, x
    }
    
    cout << pipeline;

    return 0;
}
