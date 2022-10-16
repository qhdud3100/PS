#include <iostream>

using namespace std;

/*
    두 팀으로 나누기 -> 조합
*/


int N;
int ability[21][21];
int team[21];
int MinBalance = 100000000;


int bestBalance(){

    int start=0, link=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){ // 생각도 못한 아이디어
            if(team[i] && team[j]) start+= ability[i][j];
            else if (!team[i] && !team[j])link+= ability[i][j];
        }
    }
    //cout << "start : " << start << ", link : " << link << " \n";
    return abs(start - link);
}

void dfs(int current, int times){

    if(times == N/2){
        MinBalance = min(MinBalance, bestBalance());
        return;
    }

    for(int i = current+1;i<=N;i++){
        team[i]=1;
        dfs(i, times+1);
        team[i]=0;
    }

}

int main(){

    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> ability[i][j];
        }
    }

    dfs(0,0);
    cout << MinBalance;


    return 0;
}