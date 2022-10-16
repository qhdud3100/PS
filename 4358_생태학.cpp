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

    아이디어: 전형적인 map 문제

    구현:
    input 갯수 안알려주고 종료될때까지 계속 입력받는 것이 핵심! 
    (콘솔 입력에서는 수동으로 EOF를 해줘야하는데 control + D 누르면 된다.)
    
    맵은 입력하면 자동으로 sorting이 된다. 

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    string tree;
    int n=0;
    map<string, int> m;

    //입력 
    while(getline(cin, tree)){
        n++;
        m[tree]++;
    }
    
    //소수점 고정
    cout<< fixed;
    cout.precision(4);

    //출력
    map<string, int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        cout << iter->first << " " << (double)iter->second/n*100 << "\n";
    }



    return 0;
}
