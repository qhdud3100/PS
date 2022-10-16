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

    trial 1: 시간초과

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int T, N;
    string S;
    bool is_fail=false;

    vector<string> v;

    cin >> T;
    while(T--){
        cin >> N;
        while(N--){
            cin >> S;
            v.push_back(S);
        }
        sort(v.begin(), v.end());




        if(!is_fail) cout << "YES";
        v.clear();
        is_fail=false;
    }

    return 0;
}
