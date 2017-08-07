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

//Light, more light | UVa Id:10110
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1051

int main(){
    long n;
    double raiz;

    cin >> n;

    while(n != 0){
        raiz = sqrt(n);
        if(floor(raiz) == ceil(raiz)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

        cin >> n;
    }

    return 0;
}
