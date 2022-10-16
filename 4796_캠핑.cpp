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

    너무 쉬워

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int L, P, V;
    int i=1;
    
    
    do{
        cin >> L >> P >> V;
        if(L==0 && P==0 && V==0) return 0;
        
        int tmp = V/P * L; // 전체 몇 묶음 있는지 * 묶음별로 휴가 몇일? 
        tmp += min(V%P, L); // 묶음 묶고 나머지도 더해줘야함. L보다 크면 그냥 L로 해야함.
        cout << "Case " << i << ": " << tmp << "\n";

    }while(i++);
    

    return 0;
}

