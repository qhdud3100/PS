#include <iostream>
#include <vector>

using namespace std;

bool possible[27];
bool visited[27];
int L, C;
vector <char> password;
bool isVowel[28]={1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};

void backTracking(int times, int current){

    if(times==L){
        int consonantCount=0;
        int vowelCount=0;

        for(int i=0;i<password.size();i++){
            if(isVowel[password[i]-'a']) vowelCount++;
            else consonantCount++;
        }
        if(vowelCount<1 || consonantCount<2) return;
        for(int i=0;i<password.size();i++){
            cout << password[i];
        }
        cout <<"\n";
        return;
    }

    for(int i=current;i<27;i++){
        if(visited[i]) continue;
        if(!possible[i]) continue;
        visited[i]=true;
        password.push_back('a'+i);

        backTracking(times+1, i);
        
        visited[i]=false;
        password.pop_back();
    }
    
}

int main(){

    char tmp;
    cin >> L >> C;
    for(int i=1;i<=C;i++){
        cin >> tmp;
        possible[tmp-'a']=true;
    }
    backTracking(0, 0);


    return 0;
}