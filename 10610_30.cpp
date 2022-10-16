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

    3의 배수 = 각 자리수의 숫자를 더했을때, 3의 배수가 됨

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    string N;
    int n, sum=0;
    bool has_zero=false;
    cin >> N;
    vector<int> v;

    for(int i=0;i<N.size();i++){
        n = N[i]-'0'; 
        sum+=n;
        v.push_back(n);
        if(n==0) has_zero = true;
    }
    
    if(sum%3!=0 || !has_zero){ //0이 없거나 각자리수의 합이 3의 배수가 안되면 => 30의 배수가 안됨.
        cout << -1;
        return 0;
    }

    sort(v.begin(), v.end(), greater<int>());
    for(int i=0;i<v.size();i++){
        cout << v[i];
    }


    return 0;
}

