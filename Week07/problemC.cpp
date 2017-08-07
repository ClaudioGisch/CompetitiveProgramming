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

//Fibonacci, How Many Calls? | URI Id:1029
//https://www.urionlinejudge.com.br/judge/en/problems/view/1029

int calls;

int fib(int a){
    calls++;
    if(a == 1){
        return 1;
    }
    if(a == 0){
        return 0;
    }
    return fib(a-1) + fib(a-2);
}

int main(){
    int n, x, result;
    cin >> n;
    while(n > 0){
        calls = 0;
        cin >> x;
        result = fib(x);
        cout << "fib(" << x << ") = " << (calls - 1) << " calls = " << result << endl;
        n--;
    }

    return 0;
}
