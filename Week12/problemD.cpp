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

//Hello World! | UVa Id:11636
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2683

int main(){
    int n;
    int cases = 0;
    cin >> n;
    while(n >= 0){
        cases++;
        cout << "Case " << cases << ": " << ceil(log2(n)) << endl;
        cin >> n;
    }

    return 0;
}
