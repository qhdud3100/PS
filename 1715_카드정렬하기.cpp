#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << "\n" << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴


int main() {

    priority_queue<int, vector<int>, greater<int> > pq;
    int N, n, sum=0;
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> n;
        pq.push(n);
    }

    if(pq.size()==1){
        cout << 0;
        return 0;
    }
    
    while(!pq.empty()){ //비어있기 전까지
        // 제일 작은거 두개를 꺼낸다. 
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        //sum에 더한다. 
        sum+= min1+min2;

        // 작은거 두개를 합쳐서 다시 넣는다. 
        if(pq.empty()) break;
        pq.push(min1+min2);

    }

    cout<< sum;


    return 0;
}
