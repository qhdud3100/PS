#include <iostream>
#include <vector>


using namespace std;
typedef pair<int, int> node;

//미해결...
//https://hibee.tistory.com/199 참고

int N, M;
int map[9][9]={0,};
int tmp[9][9]={0,};
int Min=100000;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dir[9][9]={0,};
vector <node> cctv;

void copy_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp[i][j] = map[i][j];
        }
    }
}

void paste_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = tmp[i][j];
        }
    } 
}

void print_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void detect(int currentI, int currentJ, int direction){


    int nx = currentJ;
    int ny = currentI;

    while(1){
        nx+= dx[direction];
        ny+= dy[direction];
        if(ny >= N || ny < 0 || nx >= M || nx < 0) break;
        if(map[ny][nx] == 6) break;
        if(map[ny][nx]==0) map[ny][nx] = 7;
    }
    
}

void extend_cctv(int currentI, int currentJ, int direction, int type){

    //* currentI, currentJ에서 direction으로 뻗어나가기
    //* 뻗어나가는 방식은 type에 의해 결정됨
    
    switch (type)
    {
    case 1:
        detect(currentI, currentJ, direction);
        break;
    case 2:
        detect(currentI, currentJ, direction);
        detect(currentI, currentJ, (direction+2)%4);
        break;
    case 3:
        detect(currentI, currentJ, direction);
        detect(currentI, currentJ, (direction+1)%4);
        break;
    case 4:
        detect(currentI, currentJ, direction);
        detect(currentI, currentJ, (direction+1)%4);
        detect(currentI, currentJ, (direction+2)%4);
        break;
    case 5:
        detect(currentI, currentJ, direction);
        detect(currentI, currentJ, (direction+1)%4);
        detect(currentI, currentJ, (direction+2)%4);
        detect(currentI, currentJ, (direction+3)%4);
        break;
    default:
        break;
    }


}

void dfs(int cctv_index){ // 몇번째 cctv인지

    if(cctv_index == cctv.size()){

        copy_map();

        // TODO : 마지막까지 갔을때 퍼트리기
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]>=1 && map[i][j]<=5){ //* cctv면
                    extend_cctv(i,j,dir[i][j], map[i][j]);
                }
            }
        }
        // print_map();

        int empty_count=0;
        // TODO : 빈공간 수 계산하고 최솟값 저장
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]==0){ 
                    empty_count++;
                }
            }
        }
        Min = min(Min, empty_count);

        paste_map();
        return;
    }

    int currentI = cctv[cctv_index].first;
    int currentJ = cctv[cctv_index].second;


    for(int i=0;i<4;i++){
        if(map[currentI][currentJ] == 5 && i > 1) continue;
        if(map[currentI][currentJ] == 2 && i > 2) continue;
        dir[currentI][currentJ]=i;
        dfs(cctv_index+1);
        dir[currentI][currentJ]=0;
    }
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]>=1 && map[i][j]<=5){
                cctv.push_back(node(i,j));
            }
        }
    }

    dfs(0);
    cout << Min;

    return 0;
}