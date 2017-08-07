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

//Feynman | UVa Id:12149
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3301

int main(){
    int n;
    cin >> n;
    while(n != 0){
        int sum = 0;
        for(int i = n; i > 0; i--){
            sum = sum + (i * i);
        }
        cout << sum << endl;
        cin >> n;
    }
    return 0;
}
