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

    아이디어: 쉬운 것 같음  
    구현: 테스트케이스는 다 맞는데 자꾸 에러가남.
    못찾았던 반례 - 

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3 

    int frequency[26]={0,};
    int odd_idx=-1; // 홀수번 등장한 알파벳의 index
    string s;
    string front;
    string back;
    string res;

    cin >> s;

    for(int i=0;i<s.length();i++){
        frequency[s[i]-'A']++;
    }

    for(int i=0;i<26;i++){
        if(frequency[i]%2==1){ 
            if(odd_idx==-1) odd_idx=i; // 처음 등장하는 홀수면
            else{
                cout << "I'm Sorry Hansoo";
                return 0;
            } // 이미 홀수가 등장했으면 
        }
        for(int j=0;j<frequency[i]/2;j++){ 
            char c = i+'A';
            front+=c;
            back+=c;
        }
    }

    reverse(back.begin(), back.end());
    char mid;

    if(odd_idx>-1){ //홀수번 등장한 char이 있으면 
        mid = odd_idx+'A';
        res = front+mid+back;
    }else{
        res = front+back;
    }
    
    
    cout << res;

    

    return 0;
}
