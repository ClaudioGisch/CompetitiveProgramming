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

//Farm Robot | URI Id:2349
//https://www.urionlinejudge.com.br/judge/en/problems/view/2349

int main(){
    int n, c, s, command;
    while(cin >> n >> c >> s){
        int robot = 1;
        int pass = 0;
        if(s == 1){
            pass++;
        }
        for(int i = 0; i < c; i++){
            cin >> command;
            robot += command;
            if(robot <= 0){
                robot = n;
            }
            if(robot > n){
                robot = 1;
            }
            if(robot == s){
                pass++;
            }
        }
        cout << pass << endl;
    }
    return 0;
}