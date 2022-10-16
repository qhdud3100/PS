#include <iostream>
using namespace std;

int main(){

    int N, L;
    int location[1001]={0,};
    int redLight[101], greenLight[101];

    cin >> N >> L;
    for(int i=1;i<=N;i++){
        cin >> location[i] >> redLight[i] >> greenLight[i];
    }

    int t=0;
    for(int i=1;i<=N;i++){
        t += location[i]-location[i-1];
        if(t%(redLight[i]+greenLight[i]) > redLight[i]) continue;
        else{
            t += (redLight[i]-t%(redLight[i]+greenLight[i]));
        }
    }
    t+= L-location[N];

    cout << t;
    
    return 0;
}