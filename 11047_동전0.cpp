#include <iostream>
using namespace std;

int main(){

    int N, K;
    int A[11];
    int quotient;
    int sum=0;

    cin >> N >> K;

    for(int i=0;i<N;i++) cin >> A[i];
    
    for(int i=N-1;i>=0;i--){
        if(K/A[i] == 0) continue;

        sum += K / A[i];
        K = K % A[i];
        if(K==0) break;
    }

    cout << sum;

    return 0;
}

