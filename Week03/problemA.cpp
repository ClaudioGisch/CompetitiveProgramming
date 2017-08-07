#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Andy's Second Dictionary | UVa Id:11062
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2003

int main(){
    char input;
    string word;
    string line;
    string aux;

    map<string, string> dic;
    while(getline(cin, line)){
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        replace_if(line.begin(), line.end(), [](char c){ return ((c >= 32 && c <= 96) || c>=123) && c != '-'; }, ' ');
        stringstream stream;
        stream << line;
        while(stream >> word && !stream.eof()){
            if(!aux.empty()){
                word = aux + word;
            }
            aux.clear();
            dic[word] = word;
        }
        if(!aux.empty()){
            word = aux + word;
            aux.clear();
        }
        if(word.back() == '-'){
            word.pop_back();
            swap(aux, word);
        }
        else{
            dic[word] = word;
        }
    }
    map<string, string>::iterator it;
    for (it=dic.begin(); it!=dic.end(); it++){
        cout << it->first << endl;
    }
    return 0;
}
