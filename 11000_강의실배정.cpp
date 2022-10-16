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

    아이디어: pq를 이용한다는 힌트만 얻음
    정렬 순서 - 시작 시간 기준으로 or 끝나는 시간 기준으로
    queue 입력 방식 - 시작 시간을 기록할껀지 or 끝나는 시간을 기록할껀지
    를 잘 고민해야함. 
    " 끝나는 시간을 queue에 넣었고 시작 시간 기준으로 정렬하였다. "
    
    구현: 내가 함!!

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int N;
    priority_queue<int, vector<int>, greater<int> > end_time; //현재 모든 강의실마다 각각 끝나는 시간
    vector<pair<int, int> > lecture; //모든 수업의 시작시간, 끝나는 시간

    cin >> N;
    for(int i=0;i<N;i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        lecture.push_back(make_pair(tmp1, tmp2));
    }
    sort(lecture.begin(), lecture.end());

    for(int i=0;i<N;i++){
        if(end_time.empty() || end_time.top() > lecture[i].first){ // 비어있으면 그냥 넣는다. 제일 빨리 끝나는 강의실인데도 다음 수업 시작시간보다 늦게끝나면 그냥 새로운 강의실을 써야함.
            end_time.push(lecture[i].second);
        }else{ // 현재 강의실에 다음 강의를 넣을 수 있으면? 
            end_time.pop();
            end_time.push(lecture[i].second);
        }
        // if(!end_time.empty()) print2(end_time.top(), lecture[i].first);
        
    }
    cout << end_time.size();

    return 0;
}
