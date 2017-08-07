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

//Bee | UVa Id:11000
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1941

int fib(int n){
    if(n < 2){
        return n;
    }else{
        return fib(n - 1) + fib(n-2);
    }
}

int main(){
    long n;
    cin >> n;
    while(n != -1){
        long m = 0;
        long f = 1;
        long nm, nf;
        for(long i = 0; i < n + 2; i++){
            nf = m;
            nm = f + m;
            f = nf;
            m = nm;
        }
        cout << m-1 << " " << m + f - 1 << endl;
        cin >> n;
    }
    return 0;
}
