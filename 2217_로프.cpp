#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>  // sorting 류
#include <limits.h> // INT_MAX

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }


/*-------------------------------------------------------------------------

    값을 입력받는 동시에 min을 갱신해가면서 바로 처리할 수 있다. -> 2 2 2 6 6 의 경우 12가 아니라 10이라고 나온다. -> 다 받아놓고 정렬을 해야한다. 

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int N;
    int length;
    int max_weight=0;

    cin >> N;
    vector<int> v(N);

    for(int i=0;i<N;i++){ //몇번째 로프까지 고려할때
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());	// 내림차순 정렬 

    for(int i=0;i<N;i++){

        int n = i+1; //로프 n개까지 고려할때 

        if(max_weight < n * v[i]){
            max_weight = n * v[i];
        }
    }
    
    cout << max_weight;

    return 0;
}
