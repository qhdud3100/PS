#include<iostream>

using namespace std;

int N, Count=0;

void backTracking(long old, int digit){ //현재까지의 숫자, digit
    
    cout << Count << ", " << old<< "\n";

    if(old > 987654321){
        cout << -1;
        return ;
    }

    Count++;
    if(Count==N){
        cout << old;
        exit(0);
    }

    for(int n=0;n<=9;n++){
        if(old%10 > n){
            int New = old * 10 + n;
            backTracking(New, digit+1);
        }
    }

}

int main(){

    cin >> N;
    


    return 0;
}