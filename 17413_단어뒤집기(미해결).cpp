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

    아이디어: 안어려움
    구현: 반례를 못찾겠다;

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    string S, tmp="", res="";
    getline(cin, S);

    bool is_tag = false;
    
    for(int i=0;i<=S.length();i++){
        if(is_tag){
            tmp+=S[i];
            if(S[i]=='>'){
                is_tag=false;
                res+=tmp;
                tmp="";
            }
        }else{
            if(S[i]=='<'){
                is_tag =true;
                if(tmp.length()==0) {
                    tmp=S[i];
                    continue;
                }
                reverse(tmp.begin(), tmp.end());
                res+=tmp;
                tmp=S[i];
            }else if(S[i]==' ' || i==S.length()){
                if(tmp.length()==0) continue;
                reverse(tmp.begin(), tmp.end());
                res+=tmp+S[i];
                tmp="";
            }else{ //문자일때
                tmp+=S[i];
            }

        }
        


    }

    cout << res;

    return 0;
}
