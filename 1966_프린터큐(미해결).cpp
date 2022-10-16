#include <iostream>
#include <queue>
#include<functional>

/*
    미해결. 구현에서 막힘
*/
using namespace std;


struct document{
    int index;
    int num;
};

void print(queue<document>que);

int main(){

    queue <document>que;
    priority_queue <int> p_que;
    int N;
    int n, m;
    scanf("%d", &N);
    
    for(int i=0;i<N;i++){

        scanf("%d %d", &n, &m);
        // 큐를 채워 넣는다. 
        for(int j=0;j<n;j++){
            document tmp;
            int t;
            scanf("%d", &t);
            tmp.index=j;
            tmp.num=t;
            que.push(tmp);
            p_que.push(t);
        }

        // p_큐의 첫번째 원소 빼기. top에 저장
        int top = p_que.top();
        p_que.pop();
        int count=1;
        while(!que.empty()){
            // 큐에서 front 원소의 num가 top보다 작으면
            if(que.front().num<top){
                //빼서 맨 뒤에 다시 넣기
                document tmp;
                tmp=que.front();
                que.pop();
                que.push(tmp);
            }else{
            // 맞으면
                document tmp;
                tmp=que.front();
                que.pop();
                if(tmp.index==m)printf("%d\n", count);
                else count++;
                //빼서 index 확인 index=m이면 출력하기
                top = p_que.top();
                p_que.pop();
            }
        }
        break;
    }



    return 0;
}

void print(queue<document>que){
    printf("queue: ");
    while(!que.empty()){
        document tmp;
        tmp = que.front();
        que.pop();
        printf("%d  ", tmp.num);
    }
}