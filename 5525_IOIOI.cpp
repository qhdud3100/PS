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

    아이디어
    초보: "큰단어 안에 포함된 작은단어" 유형 적용 
    중급: 인터넷 참고
    

 -------------------------------------------------------------------------*/

int N, M;
string S, P;
bool is_success=true;
int cnt=0;
int rep=0; // OI repetition count

void solve1(){

    // P 만들기
    while(N--){
        P+="IO";
    }
    P+="I";

    // S 안에 P가 몇 번 들어가는지 계산
    for(int i=0;i<=S.length()-P.length();i++){
        for(int j=0;j<P.length();j++){
            if(S[i+j] != P[j]){
                is_success=false;
                break;
            }
        }
        if(is_success) cnt++;
        is_success=true;
    }

    cout << cnt;

}

void solve2(){

    int idx=0;

    while(1){

        if(idx>=M) break;
        if(S[idx] =='I'){
            while(1){
                if(idx>=M) break;
                if(S[idx+1]=='O' && S[idx+2]=='I'){
                    rep++;
                }else{
                    rep=0;
                    break;
                }
                if(rep>=N) cnt++;
                idx+=2;
            }
        }
        idx++;

    }

    cout << cnt;

}

int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3


    cin >> N >> M >> S;

    solve2();    

    return 0;
}
