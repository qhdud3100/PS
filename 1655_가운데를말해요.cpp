#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    insight 1: 매번 nlogn씩 걸리는 sorting을 하면 n*n*logn이라 시간초과다.
    insight 2: 데이터를 추가할때마다 알아서 sorting되는 것. 심지어 매번logn 시간씩밖에 안걸림. 이 자료구조는 무엇일까요? 
    insight 3: priority_queue는 indexing 기능을 제공하지 않는다. 이럴땐 어떻게 인위적으로 구현할 수 있을까요?
    -> 두개의 queue를 사용한다. 
    insight 4: priority queue에서는 front값에 접근하지 못하므로 large queue는 오름차순으로 만든뒤 top값을 쓴다. 
*/

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> small_que;
    priority_queue<int, vector<int>, greater<int> > large_que;
    int N, num;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num;
        
        // 항상 n+1:n 비율로 있어야함. 그래야 앞에꺼에서 top 원소를 중간값으로 쓸 수 있다.
        if(small_que.size()==large_que.size()+1){ // large에 하나 추가한다.
            large_que.push(num);
        }else{ // 같을때 -> small에 하나 추가한다. 
            small_que.push(num);
        }

        if(!large_que.empty() && !small_que.empty() && large_que.top() < small_que.top()){
            int small_top = small_que.top(); small_que.pop();
            int large_top = large_que.top(); large_que.pop();

            large_que.push(small_top);
            small_que.push(large_top);
        }

        cout << small_que.top()<<"\n";

    }


    return 0;
}



/*

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    
    priority_queue<int> small_que;
    priority_queue<int, vector<int>, greater<int> > large_que;
    int N, num;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num;
        
        // 항상 n+1:n 비율로 있어야함. 그래야 앞에꺼에서 top 원소를 중간값으로 쓸 수 있다.
        if(small_que.size()==0) small_que.push(num);
        else if(small_que.size()==large_que.size()+1){ // large에 하나 추가한다.

            if(small_que.top()<=num) large_que.push(num);
            else { // small에서 하나 쫒아내서 large에 넣은 다음에 small에 넣는다. 
                large_que.push(small_que.top());
                small_que.pop();
                small_que.push(num);
            }
            
        }else{ // 같을때 -> small에 하나 추가한다. 

            if(num <= large_que.top()) small_que.push(num);
            else{ //large
                small_que.push(large_que.top());
                large_que.pop();
                large_que.push(num);
            }
        }

        cout << small_que.top()<<"\n";

    }


    return 0;
}

*/