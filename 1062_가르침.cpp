#include <iostream>

using namespace std;

int N, K;
string words[51];
int alphabet[27];
int Max;

int readCount(){

    int count=0;

    for(int i=0;i<N;i++){
        int flag=1;
        for(int j=0;j<words[i].length();j++){
            if(alphabet[words[i].at(j)-'a']==0){
                flag=0;
                break;
            }
        }
        if(flag==1) count++;
    }
    return count;
}

void dfs(int depth, int si){

    if(depth==K){
        Max = max(Max, readCount());
        return;
    }

    for(int i=si;i<26;i++){
        if(alphabet[i]==0){
            alphabet[i]=1;
            dfs(depth+1, i);
            alphabet[i]=0;
        }
    }
}

int main(){

    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> words[i];
    }
    if(K<5){
        cout << 0;
        return 0;
    }
    K=K-5; // a, n, t, c, i는 꼭 배워야하는거니까
    alphabet['a'-'a']=1;
    alphabet['n'-'a']=1;
    alphabet['t'-'a']=1;
    alphabet['c'-'a']=1;
    alphabet['i'-'a']=1;

    dfs(0,0);
    cout << Max;

    return 0;
}