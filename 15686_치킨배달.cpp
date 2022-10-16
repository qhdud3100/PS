#include <iostream>
#include <vector>
#include<cstring>


using namespace std;

int map[51][51];
int N, M;
int MinChickenDist=10000000;
int distMap[51][51];

int chickenDist(){
    
    int distSum=0;
    for(int i=0; i<51; i++){
        memset(distMap[i], 1, sizeof(distMap[i]));
    }

    vector<pair<int, int> > chicken;
    //어디가 치킨집인지 파악하기
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==3){
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    for(int k=0;k<chicken.size();k++){
        int chickenI = chicken[k].first;
        int chickenJ = chicken[k].second;


        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                distMap[i][j]=min(distMap[i][j], abs(chickenI-i) + abs(chickenJ-j));
            }
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cout << distMap[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";

    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(map[i][j]==1){
                distSum+=distMap[i][j];
            }
        }
    }
    return distSum;
}

void dfs(int depth, int startI, int startJ){

    if(depth==M){ // M 개 다 뽑았으면 치킨거리 계산
        MinChickenDist = min(MinChickenDist, chickenDist());
        return;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==1 && j==1){
                i = startI; // 조합 구현하는법 
                j = startJ;
            }
            if(map[i][j]==2){ //2는 그냥 치킨집 후보고 실제로 뽑힌 치킨집은 3
                map[i][j]=3;
                dfs(depth+1, i, j); // 조합 구현하는법 = 하던거까지를 startI, startJ로 보낸다. 
                map[i][j]=2;
            }
        }
    }
}


int main(){

    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }

    dfs(0, 1, 1);
    cout << MinChickenDist;

    return 0;
}