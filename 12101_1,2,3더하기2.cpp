#include <iostream>
#include <string>

using namespace std;

int cache[12];
int n, k;

void cashMaking(){
    cache[1]=1;
    cache[2]=2;
    cache[3]=4;
    for(int i=4;i<=n;i++) cache[i] = cache[i-1]+cache[i-2]+cache[i-3];
}

void makeEquation(){

    string equation="";

    while(1){
        if(n==2 && k==1) {
            equation+="1+1";
            break;
        }
        if(n==2 && k==2) {
            equation+="2";
            break;
        }
        if(n==1){
            equation+="1";
            break;
        }
        if(n==0) {
            equation.erase(equation.length()-1);
            break;
        }

        if(1 <= k && k <= cache[n-1]){
            equation+="1+";
            n=n-1;
        }else if(cache[n-1] < k && k <= cache[n-1] + cache[n-2]){
            equation+="2+";
            k=k-cache[n-1];
            n=n-2;
        }else if(cache[n-1] + cache[n-2] < k && k <= cache[n]){
            equation+="3+";
            k=k-cache[n-1]-cache[n-2];
            n=n-3;
        }else {
            cout << cache[n-1] << " , " << cache[n-1] + cache[n-2];
            break;
        }
    }
    cout << equation;

}

int main(){

    cin >> n >> k;

    cashMaking();

    if(cache[n]<k) {
        cout << -1;
        return 0;
    }

    makeEquation();

    return 0;
}