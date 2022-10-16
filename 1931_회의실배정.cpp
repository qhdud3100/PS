#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//greedy 유형
using namespace std;

// end time 기준으로 정렬을 해야한다. !!!!
// 이유는 스스로 생각해보시오

//* 우선순위 큐를 사용해서 푸는 방법 (indexing 기능이 없어서 하나씩 pop해야한다. )
struct compare{

    bool operator()(pair<int, int> a, pair<int, int> b){

        //! end time이 똑같은 경우를 처리하는 것이 중요하다.  3~3 , 1~3 인 경우에는 1~3, 3~3 두 회의를 할 수 있는데 그렇게 못하게됨. 
        if(a.second == b.second) return a.first > b.first; 
        return a.second > b.second;

    }

};

void solve_1(){

    priority_queue<pair<int,int>, vector<pair<int, int> >, compare> pq;

    int N;
    cin >> N;

    // N개의 회의 입력
    for(int i=0;i<N;i++){
        int start, end;
        cin >> start >> end;
        pq.push(make_pair(start, end));
    }

    //맨 처음꺼는 뺀다. 
    int count=1; 
    int endTmp = pq.top().second; 
    pq.pop();

    while(!pq.empty()){

        // cout << pq.top().first << ", " << pq.top().second << "\n";
        
        if(pq.top().first < endTmp){ //이전에 끝난 시간보다 빨리 시작하면 -> 버려야한다. 
            pq.pop();
        }else{ // 같거나 늦게 시작하면 -> count를 센다. 
            endTmp = pq.top().second;
            count++;
            pq.pop();
        }
        
    }

    cout << count;

}

//* 벡터로 푸는 법. sorting한 다음에 indexing으로 하나씩 접근하면 된다. 
void solve_2(){

    vector<pair<int, int> > meeting;
    int N, tmp_end=0, count=0;
    cin >> N;

    // N개의 회의 입력
    for(int i=0;i<N;i++){
        int start, end;
        cin >> start >> end;
        meeting.push_back(make_pair(end, start)); 
    }
    // 끝나는 시간으로 오름차순 sorting하고 같으면 시작시간으로 sorting 
    sort(meeting.begin(), meeting.end());
    
    for(int i=0;i<N;i++){
        if(tmp_end <= meeting[i].second){
            tmp_end = meeting[i].first;
            count++;
        }
    }
    cout << count;

}


int main(){

    //solve_1();   
    solve_2();    

    return 0;
}