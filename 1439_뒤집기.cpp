#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>  // sorting 류
#include <limits.h> // INT_MAX
#include <string>

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }


/*-------------------------------------------------------------------------

    아이디어: 3분컷
    구현: 3분컷
    
 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3


    string S;
    cin >> S;
    
    int one_count=0;
    int zero_count=0;

    for(int i=0;i<S.length();i++){
        if(i==S.length()-1 && S[i]=='0' || S[i]=='0' && S[i+1]=='1'){
            zero_count++;
        }else if(i==S.length()-1 && S[i]=='1' || S[i]=='1' && S[i+1]=='0'){
            one_count++;
        }
    }
    cout << min(zero_count, one_count);

    return 0;
}
