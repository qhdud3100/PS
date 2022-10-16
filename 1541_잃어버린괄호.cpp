#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#include <cstdio> 

/*
    문자열 tokenize가 어려웠던 문제 
    -> 문자열 전체를 받은 뒤 한 문자씩 검사하면서 num에 +=로 하나씩 붙여나가는 방법 사용
*/

using namespace std;

#define co(x) cout << x << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define co2(x, y) cout << x << ', ' << y << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string equation, num;
    int sum=0;
    bool isMinus=false;
    cin >> equation;

    for(int i=0;i<equation.size();i++){
        if(equation[i]=='+' && !isMinus){ // 더해줄때

            sum+=stoi(num);
            num="";

        }else if(equation[i]=='-' && !isMinus){ //더해줄때

            isMinus=true;
            sum+=stoi(num);
            num="";

        }else if((equation[i]=='+'  || equation[i]=='-') && isMinus){ //빼줄때
            sum-=stoi(num);
            num="";

        }else{ //숫자일때 
            num+=equation[i];
        }
    }
    if(isMinus){
        sum-=stoi(num);
    }else{
        sum+=stoi(num);
    }

    cout << sum;
    return 0;
}
