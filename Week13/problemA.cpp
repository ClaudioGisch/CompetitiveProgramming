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

//Assigning Teams | URI Id:2345
//https://www.urionlinejudge.com.br/judge/en/problems/view/2345

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        cout << abs((a+d)-(b+c)) << endl;
    }
    return 0;
}