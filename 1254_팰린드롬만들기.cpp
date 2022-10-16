#include <iostream>
#include <string>
using namespace std;

string sentence; 
int length;

bool is_palin(int index){

    int half = (length-index)/2;
    for(int i=0;i<=half;i++){
        if( sentence[index + i] != sentence[length-1-i] ){
            return false;
        }
    }
    return true;
}

int main(){

    cin >> sentence;
    length = sentence.length();

    for(int i=0;i<length;i++){
        if(is_palin(i)){
            cout << length+i;
            return 0;
        }
    }
    cout << 2*length-1;
    return 0;
}
