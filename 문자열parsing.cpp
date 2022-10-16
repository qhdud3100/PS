#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 
#include <cstdio> 


using namespace std;

#define co(x) cout << x << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define co2(x, y) cout << x << ', ' << y << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴


int main() {
    
 
    //방법 1
    char * equation;
    cin >> equation;

    char *token = strtok(equation,"+-"); // 첫 번째 token을 반환한다.

    while (token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, "+-");
    }
    

    //방벙 2
    string s, word;
    cin >> s;
    

    for(int i=0;i<s.size();i++){
        if(s[i]=='-' || s[i]=='+'){
            cout << word << ", ";
        }else{
            word+=s[i];
        }
    }

    return 0;
}
