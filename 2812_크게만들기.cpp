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

    풀이1 -> 시간초과
    N=500,000, K=500,000인 경우에는 1초가 넘게 걸림. 


    풀이2: (아이디어: 인터넷 참고, 다음에 봤을때도 인터넷 참고)

 -------------------------------------------------------------------------*/

int N, K;
string num;
string result;

void solve1(){

    int N, K;
    string num;
    string result;

    cin >> N >> K;
    cin >> num;

    int curI =0;
    int left = N-K;
    while(result.size() < left ){ //크기가 N-K가 되면 종료
        int max=0;
        int maxI=0;
        for(int i=0;i<=K;i++){
            if(max < num[i+curI]){
                max = num[i+curI];
                maxI = i+curI;
            }
        }
        K = K - (maxI - curI);
        curI = maxI + 1;
        result += num[maxI];
    }
    cout << result << "\n";
}

bool compare(pair<int, int> a, pair<int, int>b){
    if(a.first==b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
    }
}

void solve2(){

    int num;
    string answer;

    vector<pair<int, int> > v;

    for(int i=0;i<N;i++){
        scanf("%1d", &num);
        v.push_back(make_pair(num, i)); // 숫자, 인덱스 순으로 저장
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<N;i++){
        // 제일 큰걸 뽑는다. 
        
        
    }

    

}

int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    cin >> N >> K;

    //풀이 2
    solve2();
    
    return 0;
}
