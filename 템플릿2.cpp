#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

#define print(x) cout << x << '\n'; // ⭐️ 변수 출력하고 줄바꿈
#define ii pair<int, int> // ⭐️ 보통 vector랑 많이 쓴다
#define ll long long // ⭐️ 매번 long long 치고 있으면 현기증이 옴

int dx[] = {1, 0, -1, 0}; // 동 남 서 북 // ⭐️ DFS, BFS 문제 풀 때 꼭 씀
int dy[] = {0, 1, 0, -1}; // ⭐️ 이렇게 안하고 2x4 배열로 만들어 쓰는 사람들도 있는 것 같다
int INF = 1e9 + 7; // ⭐️ 의외로 자주 쓰는 수. 자주 쓰고 말고는 문제를 풀면서 생각해보면 될 문제



int main() {

  ios_base::sync_with_stdio(false); // ⭐️ cpp 필수1
  cout.tie(nullptr); // ⭐️ cpp 필수2
  cin.tie(nullptr); // ⭐️ cpp 필수3
  
  //freopen("tc.txt", "r", stdin); // ⭐️ tc.txt 라는 파일에 예제 입력을 복붙해 두면 이후 코드 실행할 때마다 콘솔에 매번 입력하지 않고 자동으로 파일을 읽어서 결과를 출력한다.

  priority_queue<int, vector<int>, greater<int> > pq; // 오름차순 priority queue
  priority_queue<int> pq; //내림차순 priority queue

}
