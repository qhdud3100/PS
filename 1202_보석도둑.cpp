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

    아이디어: 인터넷 참고 (코드 이해하는것도 오래걸림..)

    구현:
    큐의 원소에 매 번 접근할때는 !q.empty() 조건을 달아줘야한다. 
    long long해줘야함.
    55번쨰 줄 부등호 <에서 <=로 
 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int N, K;
    int m, v, c;
    priority_queue<int> pq;
    vector<pair<int, int> > gem;
    vector<int> bag;
    int gem_index=0;
    long long sum=0;

    cin >> N >> K;

    for(int i=0;i<N;i++){
        cin >> m >> v;
        gem.push_back(make_pair(m,v));
    }

    for(int i=0;i<K;i++){
        cin >> c;
        bag.push_back(c);
    }
    
    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());
    
    for(int i=0;i<K;i++){
        while(gem_index<N && gem[gem_index].first <= bag[i]){ //내가 지금 수용할 수 있는 양보다 작을때까지 넣는다. 
            pq.push(gem[gem_index].second);
            gem_index++;
        }
        if(!pq.empty()){
            sum+=(long long)pq.top();
            pq.pop();
        }
    }

    cout << sum;
    

    return 0;
}
