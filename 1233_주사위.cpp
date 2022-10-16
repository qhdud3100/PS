#include <iostream>

using namespace std;

int sum[81]={0,};

int main(){

    int s1, s2, s3, Max=0;
    cin >> s1 >> s2 >> s3;

    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                sum[i+j+k]++;
                Max = max(Max, sum[i+j+k]);
            }
        }
    }
    for(int i=1;i<=80;i++){
        if(sum[i]==Max){
            cout << i;
            break;
        }
    }

    return 0;
}
