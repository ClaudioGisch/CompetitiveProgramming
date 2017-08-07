#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//What's Cryptanalysis? | UVa Id:10008
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=949

bool compare (const pair<int, char> &i, const pair<int, char> &j){
    if(i.first == j.first){
        return i.second < j.second;
    }else{
        return i.first > j.first;
    }
}

void countChars(string text){
    map<char, int> dic;
    for(int i = 0; i < text.size(); i++){
        if(isalpha(text[i])){
            if(dic[toupper(text[i])]){
                dic[toupper(text[i])] = dic[toupper(text[i])] + 1;
            }else{
                dic[toupper(text[i])] = 1;
            }
        }
    }
    vector<pair<int, char>> orderChar;
    for(map<char,int>::iterator it = dic.begin(); it != dic.end(); it++){
        orderChar.push_back(make_pair(it->second, it->first));
    }
    sort(orderChar.begin(), orderChar.end(), compare);
    for(int i = 0; i < orderChar.size(); i++){
        cout << orderChar[i].second << " " << orderChar[i].first << endl;
    }
}

int main(){
    int n;
    cin >> n;
    string text;
    string line;
    for(int i = 0; i <= n; i++){
        getline(cin, line);
        text = text + line;
    }
    countChars(text);
    return 0;
}