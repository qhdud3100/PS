#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int add[20][200]={0,};
int age_map[20][200]={0,};
int nutrient_map[20][200];
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={1,0,-1,-1,-1,0,1,1};

void spread(int curY, int curX){
    for(int i=0;i<8;i++){
        int nx = curX+dx[i];
        int ny = curY+dy[i];
        if(ny<=0 || nx<=0 || ny>=N || nx>=N) continue;
        if(age_map[ny][nx]==0) age_map[ny][nx]=1;
    }
}

void spring(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(age_map[i][j]==0) continue;
            if(nutrient_map[i][j]<age_map[i][j]){ //죽는다...
                nutrient_map[i][j]=-1;
            }else{
                nutrient_map[i][j]=nutrient_map[i][j]-age_map[i][j];
                age_map[i][j]++;
            }
        }
    }

}
void summer(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(nutrient_map[i][j]!=-1) continue; //이번 봄에 죽은 것...
            nutrient_map[i][j] += age_map[i][j]/2;
            age_map[i][j]=0;
            
        }
    }
}

void fall(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(age_map[i][j]==0) continue;
            if(age_map[i][j]%5==0) spread(i,j);
        }
    }
}
void winter(){

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            nutrient_map[i][j]+=add[i][j];
        }
    }

}

void print_map(int map[][200]){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout << map[i][j]<< " ";
        }
        cout <<"\n";
    }
    cout << "\n";
}

int main(){

    cin >> N >> M >> K;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> add[i][j];
        }
    }

    int x, y, age;

    for(int i=1;i<=M;i++){
        cin >> x >> y >> age;
        age_map[y][x] = age;
    }

    fill(&nutrient_map[0][0], &nutrient_map[19][200], 5);  

    for(int i=1;i<=K;i++){
        spring();
                // print_map(nutrient_map);
        summer();
                // print_map(nutrient_map);
        fall();
                // print_map(nutrient_map);
        winter();

        print_map(age_map);
        print_map(nutrient_map);
        cout << "\n\n";

    }

    int survive_sum=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(age_map[i][j]!=0) survive_sum++;
        }
    }
    cout << survive_sum;

    return 0;
}
