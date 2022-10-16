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
    
    아이디어: 쉬움

    구현: (런타임에러 -> 구글 검색)
    다음으로 넘어갈때, i+=word.size()가 아니라 i+=word.size()-1;
    for문에서 어차피 i++ 해주기 때문에

    문장길이가 단어길이보다 짧은 경우를 생각하지 않았음. 따로 처리해줘야함.

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    string sentence;
    string word;
    int has_word=1, count=0;

    getline(cin, sentence);
    getline(cin, word);

    if(word.size() > sentence.size()) {
        cout << 0;
        return 0;
    }

    for(int i=0;i<=sentence.size()-word.size();i++){
        for(int j=0;j<word.size();j++){
            if(sentence[i+j] != word[j]){
                has_word=false;
                break;
            }
        }
        if(has_word ==true) {
            count++;
            i+=word.size()-1;
        }
        has_word = true;    

    }
    cout << count;

    return 0;
}
