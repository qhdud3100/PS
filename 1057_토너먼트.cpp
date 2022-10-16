#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int N, r=1;
    int p1, p2;
    cin >> N >> p1 >> p2;

    while(N>=1){

        p1 = (p1+1)/2;
        p2 = (p2+1)/2;
        //cout << r <<" : " << p1 << ", "<<p2<<"\n";
        
        if(p1==p2){
            break;
        }
        
        N=N/2;
        r++;
    }

    cout << r;
    return 0;
}