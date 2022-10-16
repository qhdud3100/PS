#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    sort(v.begin(), v.end()); //오름차순, 작은거 -> 큰거
    sort(v.begin(), v.end(), greater<int>()); //내림차순, 큰거 -> 작은거

}