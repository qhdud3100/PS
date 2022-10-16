#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int height[9];
    int sum=0;
    int tmp;

    for(int i=0;i<9;i++){
        cin >> tmp;

        height[i]=tmp;
        sum+=tmp;
    }
    sort(height, height+9);

    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(i!=j && sum-height[i]-height[j]==100){
                for(int k=0;k<9;k++){
                    if(k!=i && k!=j) cout << height[k] <<"\n";
                }
                return 0;
            }
        }
    }



    return 0;
}