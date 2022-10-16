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

    아이디어: 유형만 참고
    S에서 T로 접근하는게 아니라 T에서 S로 접근해보기!!!
    
 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3


    string S, T;

    cin >> S >> T;

    while(1){

        if(S==T){
            cout << 1;
            break;
        }else if(S.length() >= T.length()){
            cout << 0;
            break;
        }
        
        if(T[T.length()-1]=='A'){
            T.erase(T.length()-1, 1);
        }else if(T[T.length()-1]=='B'){
            T.erase(T.length()-1, 1);
            reverse(T.begin(), T.end());
        }


    }

    

    return 0;
}
