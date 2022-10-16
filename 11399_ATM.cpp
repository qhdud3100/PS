#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> P;

int main(){

    int N;
    int sum=0;

    cin >> N;

    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        P.push_back(tmp);
    }
    
    sort(P.begin(), P.end());
    for(int i=0;i<P.size();i++){
        for(int j=0;j<=i;j++){
            sum+=P[j];
        }
    }
    cout << sum;

    return 0;
}