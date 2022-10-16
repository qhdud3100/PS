#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;


int main() {


    //선언
    int N, tmp, sum=0;
    vector<int> A; //* N개의 원소를 가진 벡터 A를 만든다. 
    vector<int> B;

    //입력
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        A.push_back(tmp);
    } 
    for(int i=0;i<N;i++){
        cin >> tmp;
        B.push_back(tmp);
    } 

    //문제풀이
    sort(A.begin(), A.end()); // 기본은 오름차순이고
    sort(B.begin(), B.end(), greater<int>()); // 내림차순을 하고싶으면 greater<int>()를 세 번째 인자로 넣는다. 

    for(int i=0;i<N;i++){
        sum+=A[i] * B[i];
    }

    //출력
    cout << sum;

    return 0;
}
