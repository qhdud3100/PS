#include <iostream>
using namespace std;

int main(){
    int count=0;
    int tmp;
    string results[5]={"D", "C", "B", "A", "E"};

    for(int i=0;i<3;i++){
        count=0;
        for(int j=0;j<4;j++){
            cin >> tmp;
            if(tmp) count++; 
        }
        //cout << count << "\n";
        cout << results[count] << "\n";
    }

}