#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }



/*-------------------------------------------------------------------------*

    7개를 사야할때 꼭 묶음 1개 낱개 1개 살 필요가 없음. 묶음 2개를 사도 됨. 이것을 간과했다.
    답 확인함.
    tip: 여러 패키지 중에 하나를 고르는 문제에서는 입력을 받는 순간 매번 min을 통해 값을 구해도된다. 
    제일 가성비있는 것을 고르는거라 이전 값이 중요한게 아니기 때문에.

 *-------------------------------------------------------------------------*/

int main() {
    
    int N, M;
    vector<int> bundle; 
    vector<int> indi;
    int a, b;

    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        bundle.push_back(a);
        indi.push_back(b);
    }
    
    sort(bundle.begin(), bundle.end());
    sort(indi.begin(), indi.end());

    // 전부 낱개로 사는 것, 전부 묶음으로 사는 것, 딱 떨어지게 사는 것 중에 제일 싼 것
    int share = N/6;
    int remainder = N%6;


    int money = min((1+share)*bundle[0], N*indi[0]);
    money = min(money, share*bundle[0] + remainder*indi[0]);

    cout << money;
    
    return 0;
}
