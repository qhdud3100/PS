#include<iostream>
using namespace std;
#define MAX_SIZE 100050

int heap[MAX_SIZE];
int last=0;

//////////실패//////////

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int x){
    heap[++last] = x;
    int child=last, parent=child/2;

    while(child>1 && heap[child]>heap[parent]){
        swap(&heap[child], &heap[parent]);
        child = parent;
        parent = parent/2;
    }
    
}
int pop(){

    if(last==0) return 0;
    int tmp = heap[1];
    heap[1]=heap[last--];
    int parent=1, child =2;

    while(child <= last && heap[parent] < heap[child] || heap[parent] < heap[child+1]){
        if(heap[child]>heap[child+1] && heap[parent]<heap[child]){ //왼쪽자식 > 오른쪽 자식
            swap(&heap[child], &heap[parent]);
        }else if(heap[child]<heap[child+1] && heap[parent]<heap[child+1]){ //왼쪽자식 < 오른쪽 자식
            swap(&heap[child+1], &heap[parent]);
        }
        parent = child;
        child = child*2;

    }

    return tmp;
}

void print(){
    for(int i=1;i<=last;i++) cout<<"\t"<<heap[i]<<"\t";
    cout<<"\n";
}

int main(){
    
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x==0) cout << pop();
        else if(x>0) push(x);
    }
    

    return 0;
}