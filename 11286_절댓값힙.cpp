#include <iostream>
#include <queue>
#include <cstdlib>
#include <functional>
using namespace std;

struct cmp{

    bool operator()(const int x, const int y){
        if(abs(x)==abs(y)) return x>y;
        return abs(x)>abs(y);
    }

};

int main(){
    
    int N;
    cin >> N;
    priority_queue<int, vector<int>, cmp> q;

    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x==0) {
            if(q.size()==0) cout<<"0\n";
            else{
                cout<< q.top()<<"\n";
                q.pop();
            }
        }
        else q.push(x);
    }
    


    return 0;
}