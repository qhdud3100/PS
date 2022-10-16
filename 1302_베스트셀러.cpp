#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>  // sorting 류
#include <limits.h> // INT_MAX
#include <string>
#include <map>

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }


/*-------------------------------------------------------------------------

    Map을 만들어서 단어가 등장할때마다 ++

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    map<string, int> m;
    int N;
    string book;
    int max_count=0;
    string max_book;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> book;
        if(m.count(book)){ //count가 1이상이라는 것은 그게 있다는 것
            m[book]++;
        }else{
            m.insert(make_pair(book, 1));
        }
    }

    map<string, int>::iterator iter;
    for(iter=m.begin(); iter!=m.end();iter++){
        if(iter->second > max_count){
            max_count = iter->second;
            max_book = iter->first;
        }
    }
    cout << max_book;


    return 0;
}
