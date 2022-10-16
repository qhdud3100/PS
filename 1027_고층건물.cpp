#include <iostream>
#include <climits>

using namespace std;

int N;
long building[51];

int left(int index){
    int count=0;
    long minLean = INT_MAX;
    for(int i=index-1;i>=1;i--){
        double Lean = (double)(building[index]-building[i])/(index-i);
        //cout <<index <<" : " << Lean << "\n";
        if(minLean>Lean) {
            minLean = Lean;
            count++;
        }
    }
    return count;

}
int right(int index){
    int count=0;
    long maxLean= INT_MIN;
    for(int i=index+1;i<=N;i++){
        double Lean = (double)(building[i] - building[index])/(i-index);
        //cout <<index <<" : " << Lean << "\n";
        if(maxLean<Lean){
            maxLean=Lean;
            count++;
        }
    }
    return count;
}

int main(){

    cin >> N;
    int maxLook=0;

    for(int i=1;i<=N;i++){
        cin >> building[i];
    }

    for(int i=1;i<=N;i++){
        int Left = left(i);
        int Right = right(i);
        maxLook = max(maxLook, Left+Right);
        //cout << Left << " + " << Right << " = " << maxLook <<"\n";
    }
    cout << maxLook;
    return 0;
}