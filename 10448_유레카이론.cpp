#include <iostream>

using namespace std;

int triangular[101]={0,};

int isTriangular(int n){

    for(int i=1;i<=50;i++){
        for(int j=i;j<=50;j++){
            for(int k=j;k<=50;k++){
                if(triangular[i]+ triangular[j]+triangular[k]==n) return 1;
            }
        }
    }
    return 0;
}

int main(){

    for(int i=1;i<=50;i++){
        triangular[i] = triangular[i-1]+i;
    }

    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        int num;
        cin >> num;
        cout << isTriangular(num) << "\n";
    }

    return 0;
}
