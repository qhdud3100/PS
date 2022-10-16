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

    아이디어: 이 문제가 뭔가 문자열문제의 기본 유형인듯하다.
    이중 반복문 쓰면서 바깥쪽에서는 전체적으로 pos 변수 써서 큰 문장 index를 이동하고
    작은 반복문에서는 작은 index 이동하면서 글자 하나씩 비교하는 형식

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3


    string A, B;
    cin >> A >> B; //A = 짧은 단어, B = 긴 단어
    int pos=0;
    int count=0;
    int max_count=0;

    while(1){

        if(pos > B.length()-A.length()) break;

        for(int i=0;i<A.length();i++){
            if(A[i] == B[pos + i]){ // 다르면 break하는 유형도 있고, 같은것만 count하는 유형도 있다. 
                count++;
            }
        }
        pos++;
        max_count = max(max_count, count);
        count=0;

    }


    //긴거 길이에서 같은 부분을 뺀다음에 길이차만큼 또 뺀다. 
    cout << B.length() - max_count - (B.length() - A.length())<<"\n";

    return 0;
}
