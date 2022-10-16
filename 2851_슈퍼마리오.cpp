#include <iostream>

using namespace std;

int main(){
    int n=0;
    int res=0;
    bool flag=false;

    for(int i=0;i<10;i++){
        int mushirum;
        cin >> mushirum;

        if(flag) continue;
        if( n+mushirum < 100 ){
            n+=mushirum;
            res = n;
        }
        else{
            if( n+mushirum-100 > 100-n ) res = n;
            else res = n+mushirum;
            flag = true;
        }
    }

    cout << res;
    return 0;
}