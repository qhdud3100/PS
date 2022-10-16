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

    

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int T, N;
    cin >> T;

    while(T--){
        cin >> N;
        priority_queue<int> ordered_length; // 통나무 길이를 크기순으로 정렬
        vector<int> length(N); // 최소 길이 차이가 나게 정렬한 것


        for(int i=0;i<N;i++){
            int tmp;
            cin >> tmp;
            ordered_length.push(tmp);
        }

        int j=0; //index
        while(!ordered_length.empty()){
            int max1 = ordered_length.top();
            ordered_length.pop();
            length[j] = max1;

            if(ordered_length.empty()) break;

            int max2 = ordered_length.top();
            ordered_length.pop();
            length[N-1-j] = max2;
            
            j++;
        }

        int max_diff=0;
        for(int i=1;i<length.size();i++){
            if (max_diff < abs(length[i] - length[i-1])){
                max_diff = abs(length[i] - length[i-1]);
            }
        }
    
        cout << max_diff << "\n";
    }


    return 0;
}
