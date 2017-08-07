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

//Square Numbers | UVa Id:11461
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2456

int main(){
    int a, b, minN, maxN;
    cin >> a >> b;
    while((a != 0) || (b != 0)){
        int i = 0;
        int n;
        minN = min(a, b);
        maxN = max(a, b);
        n = ceil(sqrt(minN));
        while((n*n) <= b){
            n++;
            i++;
        }
        cout << i << endl;
        cin >> a >> b;
    }

    return 0;
}
