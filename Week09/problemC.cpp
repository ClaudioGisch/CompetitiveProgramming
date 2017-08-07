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

#define MAX 81

using namespace std;

//Bees' ancestors | UVa Id:12459
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3890

long fibTable[MAX];


long fib(int i){
    if(fibTable[i] != 0){
        return fibTable[i];
    }else{
        fibTable[i] = fib(i-1) + fib(i-2);
        return fibTable[i];
    }
}

int main(){
    for(int i = 0; i < MAX; i++){
        fibTable[i] = 0;
    }
    fibTable[1] = 1;
    fibTable[2] = 1;
    int g;
    cin >> g;
    while(g != 0){
        cout << fib(g+1) << endl;
        cin >> g;
    }
    return 0;
}
