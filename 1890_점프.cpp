#include <iostream>

//DP 실버. 
using namespace std;

int N;
int Map[102][102];
long cache[102][102];

void DP(){
    cache[1][1]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cache[i][j]==0 || (i==N && j==N)) continue;
            int jump = Map[i][j];
            int ni = i+jump; //next I 
            int nj = j+jump; //next J
            if(ni <= N) cache[ni][j] += cache[i][j];
            if(nj <= N) cache[i][nj] += cache[i][j];
            //cout << cache[i][j]<<" ";
            //if(ni==N && j ==N) cout << i<<" , "<<j<<"\n";
            //if(i==N && nj ==N) cout << i<<" , "<<j<<"\n";
        }
        //cout <<"\n";
    }
    
    cout << cache[N][N];

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> Map[i][j];        
        }
    }

    DP();

    return 0;
}