#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


string ReverseString(const string src, int len)
{
    string reverse;

    for(int i=0;i<len;i++){
        if('a' <= src[len-i-1] && src[len-i-1] <='z' || 'A' <= src[len-i-1] && src[len-i-1] <='Z') {
            reverse+=' ';
            reverse+=src.substr(0,len-i);
            return reverse;
        }
        reverse+=src.substr(len-i-1,1);
    }
      return reverse;
}

int main(){

    string input_line;
    getline(cin, input_line);
    vector <string> lines;
    string common_type;
    string tmp;
    
    for(int i=0;i<input_line.size();i++){

        if(input_line[i]==' ' && input_line[i-1]!=','){
            common_type = tmp;
            tmp.clear();
            continue;
        }else if(input_line[i]==','){
            tmp = ReverseString(tmp,tmp.size());
            lines.push_back(tmp);
            tmp.clear();
            continue;
        }else if(input_line[i]==';'){
            tmp = ReverseString(tmp,tmp.size());
            lines.push_back(tmp);
            tmp.clear();
            continue;
        }else if(input_line[i]==' ') continue;

        tmp+=input_line[i];
    }

    

    for (int i = 0; i < lines.size(); i++)
    {
        cout << common_type;
        for(int j=0;j<lines[i].size();j++){
            if(lines[i][j] == ']'){
                cout << "[]";
                j++;
                continue;
            }
            cout << lines[i][j];
        }
        cout << ";\n";
    }
    

    return 0;
}