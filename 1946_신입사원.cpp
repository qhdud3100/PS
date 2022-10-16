#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#include <limits.h> 

using namespace std;

#define print(x) cout << x << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define print2(x, y) cout << x << ", " << y << "\n"; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴
#define printAll(x) for(int i=0;i<x.size();i++){cout << x[i] << "\n"; }


/*-------------------------------------------------------------------------

    idea (인터넷 참고)
    pair로 만들어서 정렬, 내 밑에있는 애들은 볼 필요 없고 내 위에있는 애들 중에 내가 면접 등수라도 높으면 통과다. 
    
    구현 
    큐를 사용할 수 없다. indexing기능이 없기 때문에..
    반복적으로 반복해야하기 때문에 pop을 할 수 없다. 

    //! 시간초과 -> (인터넷 참고) 
    //! 매번 나보다 위에있는 애들을 찾아볼 필요가 없다. 내 위에있는 애들 면접등수의 최솟값보다 내 면접등수가 작으면 됨.


    최솟값을 기억하는 두가지 방법
    1. index를 기억한다. //* i를 또 사용할 수 있다. 
    if(grades[temp].second > grades[i].second) { 
        result++; 
        temp=i; 
    }

    2. 값을 기억한다. 
    if(min > grades[i].second) { 
        result++; 
        min = grades[i].second; 
    }

 -------------------------------------------------------------------------*/


int main() {
    
    
    int T, N, score1, score2, count, min;
    bool isSuccess=true;
    

    cin >> T;
    while(T--){

        cin >> N;

        vector<pair<int, int> > v(N);
        count=0;
        min=INT_MAX;

        
        for(int i=0;i<N;i++){
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());
        
        for(int i=0;i<N;i++){ // 맨 첫번째 사람을 제외한 모든 사람의 정보에 대해
            if(v[i].second < min){ // 지금까지 나온 것들 중에서는 내가 제일 작아야함. => 내가 min을 갱신해야함.
                min = v[i].second;
                count++;
                //print2(v[i].first, v[i].second);
            }
        }
        cout << count<< "\n";
    }

    return 0;
}
