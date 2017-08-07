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

//Amalgamated Artichokes | UVa Id:1709
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=4782

int main(){
    int p, a, b, c, d, n;
    while(cin >> p >> a >> b >> c >> d >> n){
        long double price[n];
        long double maxPrice = -INFINITY;
        long double maxDif = 0.0f;
        for(int i = 0; i < n; i++){
            price[i] = p * (sin(a * (i+1) + b) + cos(c * (i+1) + d) + 2);
            if(price[i] > maxPrice){
                maxPrice = price[i];
            }else{
                if(abs(maxPrice - price[i]) > maxDif){
                    maxDif = maxPrice - price[i];
                }
            }
        }
        printf("%.6Lf\n", maxDif);
    }

    return 0;
}
