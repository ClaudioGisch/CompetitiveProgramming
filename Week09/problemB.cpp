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

#define MAX 52

using namespace std;

//Cutting Sticks | UVa Id:10003
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=944

int cuts[MAX][MAX];
int sol[MAX];

int cut(int left, int right){
    if(left + 1 == right){
        return 0;
    }
    if(cuts[left][right] != -1){
        return cuts[left][right];
    }

    int aux = INFINITY;

    for(int i = left + 1; i < right; i++){
        aux = min(aux, cut(left, i) + cut(i, right) + (sol[right] - sol[left]));
    }

    cuts[left][right] = aux;

    return aux;
}

int main(){
    int l, n, result;
    cin >> l;
    while(l != 0){
        //reading input
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> sol[i];
        }

        //init
        sol[0] = 0;
        sol[n+1] = l;
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                cuts[i][j] = -1;
            }
        }

        result = cut(0, n+1);
        cout << "The minimum cutting is " << result << "." << endl;
        cin >> l;
    }
    return 0;
}
