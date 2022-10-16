#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>  // sorting 류
#include <limits.h> // INT_MAX
#include <string>
#include <cstring>

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }


/*-------------------------------------------------------------------------

    아이디어: 인터넷 참고 그냥저냥 LCS 알고리즘
    구현: 답보고함 공부 좀 더 해야할듯

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    string A;
    string B;
    cin >> A >> B;
    int DP[A.length()+1][B.length()+1];

    for(int i=0; i<=A.length(); i++) { 
        memset(DP[i], 0, sizeof(DP[i])); 
    }

    for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            if(A[i-1] == B[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1;
            }else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
            // cout << DP[i][j] << " ";
        }
        // cout << "\n";
    }

    cout << DP[A.length()][B.length()];

    return 0;
}
