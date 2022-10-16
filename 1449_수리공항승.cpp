#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#include <cmath>

using namespace std;

#define print(x) cout << x << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ', ' << y << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴

/*

생각 1
'테이프 한개 당 x.5 ~ x+1.5 영역을 커버해야한다.' -> '테이프 1센티 당 한개의 구멍을 커버한다.'
생각 2
bool 배열에 구멍 정보를 저장해둔다. -> 굳이? 그냥 벡터에 구멍의 위치를 저장해둔다. 
생각 3
연속되는 구멍의 갯수를 테이프 길이로 나눈 뒤 올림한다. -> 불연속되는 구멍도 한 테이프로 막을 수 있다. ex) 1 4 6이면 길이 10짜리 테이프로 한번에 막을 수 있다.



*/

int main() {
    
    
    int N, L, n, sum=0;
    int left = -10000;
    vector<int> v;

    cin >> N >> L;
    for(int i=0;i<N;i++){
        cin >> n; // 몇번째에서 새는지 입력받음.
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        if(left <= v[i]-L){ // 현재 붙인 테이프로 지금 영역까지 보장이 안되면
            sum++; //새로 붙인다. 
            left = v[i]; //테이프의 왼쪽 끝 설정을 다시 해준다. 
        }
    }


    
    print(sum);
    return 0;
}
