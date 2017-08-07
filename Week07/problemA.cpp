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

//Etruscan Warriors Never Play Chess | UVa Id:11614
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2661

int main(){
    int n, resultInt;
    float result;
    long testes;
    cin >> testes;
    while(testes > 0){
        cin >> n;
        result = sqrt((2*n)+1);
        resultInt = (int)result;
        if((result - resultInt) > 0.5f){
            cout << resultInt << endl;
        }else{
            cout << resultInt - 1 << endl;
        }
    }
    return 0;
}
