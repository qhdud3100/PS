#include <iostream>

using namespace std;

int map[11][11];
int paper_count[6]={0,};
int Min=100000;

// 미해결. 시간초과

bool is_attachable(int si, int sj, int size){

    for(int i=si;i<si+size;i++){
        for(int j=sj;j<sj+size;j++){
            if(map[i][j]==0) return false;
        }
    }
    return true;
}
void attach(int si, int sj, int size){
    for(int i=si;i<si+size;i++){
        for(int j=sj;j<sj+size;j++){
            map[i][j]=0;
        }
    }
}

void detach(int si, int sj, int size){
    for(int i=si;i<si+size;i++){
        for(int j=sj;j<sj+size;j++){
            map[i][j]=1;
        }
    }
}

bool is_success(){
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(map[i][j]==1) return false;
        }
    }
    return true;
}

void dfs(int index){

    if(index>100) return;

    for(int i=1;i<=5;i++){
        if(paper_count[i]>5) return;
    }

    int sum=0;
    for(int i=1;i<=5;i++){
        sum+=paper_count[i];
    }
    if(sum>Min) return;

    if(is_success()){
        //cout << sum;
        Min = min(Min, sum);
        return;
    }

    // // map 출력
    // cout <<"\n";
    // for(int i=1;i<=10;i++){
    //     for(int j=1;j<=10;j++){
    //         cout << map[i][j]<<" ";
    //     }
    //     cout <<"\n";
    // }

    int currentI = index/10+1;
    int currentJ = index%10+1;

    if(map[currentI][currentJ]==1){
        // 모든 색종이 크기를 다 비교
        for(int size=5;size>=1;size--){
            if(is_attachable(currentI, currentJ, size)){
                attach(currentI, currentJ, size);
                paper_count[size]++;

                dfs(index+1);

                detach(currentI, currentJ, size);  
                paper_count[size]--;  
            }
        }

    }else{
        dfs(index+1);
    }




}

int main(){

    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin >> map[i][j];
        }
    }

    dfs(0);
    if(Min == 100000) cout << -1;
    else cout << Min;

    return 0;
}