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

//Longest Common Subsequence | UVa Id:10405
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1346

int score(char a, char b){
    if(a == b){
        return 1;
    }else{
        return -999;
    }

}

int max_value(int a, int b, int c){
    return max(a, max(b, c));
}


int main(){
    string string1;
    string string2;
    while(true){
        getline(cin, string1);
        getline(cin, string2);
        if(cin.eof()){
            break;
        }
        int sol[string1.length()+1][string2.length()+1];

        //set trivial values
        for(int i = 0; i < string1.length()+1; i++){
            sol[i][0] = 0;
        }
        for(int i = 0; i < string2.length()+1; i++){
            sol[0][i] = 0;
        }

        //solution
        for(int i = 1; i < string1.length() + 1; i++){
            for(int j = 1; j < string2.length() + 1; j++){
                sol[i][j] = max_value(sol[i][j-1], sol[i-1][j], (sol[i-1][j-1] + score(string1[i-1], string2[j-1])));
            }
        }

        cout << sol[string1.length()][string2.length()] << endl;
    }
    return 0;
}
