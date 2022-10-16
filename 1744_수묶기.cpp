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

    아이디어:
        경우를 잘 나누는 것
        각각 다른 큐에 넣는다는것 (큐마다 차순이 다름)

    구현:
        쉽네

 -------------------------------------------------------------------------*/


int main() {
    ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
    cout.tie(nullptr); // ⭐️ cpp 필수2
    cin.tie(nullptr); // ⭐️ cpp 필수3

    int N, num, a,b, sum=0;
    int one_count=0;
    int zero_count=0;
    priority_queue<int, vector<int>, greater<int> > negative;
    priority_queue<int> positive;
    
    cin >> N;
    while(N--){
        cin >> num;
        if(num<=-1){
            negative.push(num);
        }else if(num>=2){
            positive.push(num);
        }else if(num==0){ 
            zero_count++;
        }else if(num==1){
            one_count++;
        }
    }

    while(!positive.empty()){

        if(positive.size()==1){
            sum+=positive.top();
            positive.pop();
            break;
        }

        a = positive.top();
        positive.pop();
        b = positive.top();
        positive.pop();

        sum+= a*b;
    }

    
    while(!negative.empty()){

        if(negative.size()==1){
            if(zero_count) break; // 0으로 상쇄시킨다. 
            else{
                sum+=negative.top(); // sum에 더해야한다. 
                negative.pop();
            }
            break;
        }

        a = negative.top();
        negative.pop();
        b = negative.top();
        negative.pop();


        sum+= a*b;
    }


    sum +=one_count;

    cout << sum;

    return 0;
}
