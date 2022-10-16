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
    
    아이디어: (답 확인) 처음 보는 접근법;
    핵심: 측정가능한 부분이 끊이지 않아야한다. 작은 추들로 만들 수 있는 수에 큰 수를 더하면 1부터 작은 수 + 큰 수 까지 전부 만들 수 있다.

    
    가능한 무게를 먼저 배열에 색칠하는 방식도 아니고 
    모든 무게마다 방문하여 가능한지 확인하는 방법도 아니다. 
    --> 모든 추를 방문하여 "1부터 얼마까지 모두 측정 가능하니?" 를 알아야한다. 

    구현: 아이디어만 알면 쉬움

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3
    
    int N;
    cin >> N;
    long long possible_weight=0;

    vector<int> weights(N);

    for(int i=0;i<N;i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    for(int i=0;i<N;i++){
        if(possible_weight+1 < weights[i]){ // 못들때
            
            break;
        }else{
            possible_weight = possible_weight + weights[i];
            // print(possible_weight);
        }
    }
    cout << possible_weight+1;

    return 0;
}
