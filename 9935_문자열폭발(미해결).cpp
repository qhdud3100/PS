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

string S, bomb, res;
size_t nPos;

/*-------------------------------------------------------------------------

    trial 1 
    문제를 잘못이해함.
    bomb의 각 문자가 들어있으면 폭발하는게 아니라 bomb 문자가 포함되어있을때 폭발한다.

    trial 2 
    시간초과
    find 함수를 매번 호출하면 안됨. 
    한 번에 스무스하게 가야함.

    trial 3 
    아이디어: 인터넷 참고

    trial 4 (3일 뒤..)
    아이디어: 떠올림
    구현: 코드 봄
    

 -------------------------------------------------------------------------*/

void solve1(){

    cin >> S >> bomb;

    while(1){ //더이상 문자열에 남은게 없거나 못찾으면 나온다. 
        nPos= S.find(bomb); // bomb를 찾아서 index를 리턴 
        if(S.length()==0 || nPos == string::npos) break; 

        S.erase(nPos,bomb.length()); // 그 index부터 bomb 길이만큼 삭제 
    }

    if(S.length()) cout << res;
    else cout << "FRULA";

}

void solve2(){

    cin >> S >> bomb;   

    for(int i=0;i<S.length();i++){

    }


}


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    solve2();
    

    return 0;
}
