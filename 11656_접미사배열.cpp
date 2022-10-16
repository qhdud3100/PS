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

    아이디어: 쉽다 

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    vector<string> v;

    string word;
    cin>> word;

    for(int i=0;i<word.length();i++){
        string suffix = word.substr(i); //i부터 끝까지 리턴한다. 
        v.push_back(suffix); 
    }
    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        cout << v[i]<<"\n";
    }


    return 0;
}
