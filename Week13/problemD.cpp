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

//Walking in Time | URI Id:2235
//https://www.urionlinejudge.com.br/judge/en/problems/view/2235

int main(){
    int a, b, c;
    priority_queue<int> credits;
    while(cin >> a >> b >> c){
        int sum = 0;
        if((a-b) == 0 || (a-c) == 0 || (b-c) == 0){
            cout << "S" << endl;
        }else{
            credits.push(a);
            credits.push(b);
            credits.push(c);
            sum = sum + credits.top();
            credits.pop();
            sum = sum - credits.top();
            credits.pop();
            sum = sum - credits.top();
            credits.pop();
            if(sum == 0){
                cout << "S" << endl;
            }else{
                cout << "N" << endl;
            }
        }
    }
    return 0;
}
