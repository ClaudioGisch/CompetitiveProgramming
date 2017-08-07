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

//Let Me Count The Ways | UVa Id:357
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=293

int main(){
    int n;

    vector<int> coins;
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(10);
    coins.push_back(25);
    coins.push_back(50);

    while(cin >> n){
        vector<long> changes (n+1, 0) ;
        changes[0] = 1;
        for(int i: coins){
            int cont = 0;
            while(cont < n){
                cont++;
                int sum = 0;
                if((cont - i) >= 0){
                    changes[cont] += changes[cont - i];
                }
            }
        }
        if(changes[n] == 1){
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }
        else
        {
            cout << "There are " << changes[n] << " ways to produce " << n << " cents change." << endl;
        }

    }
    return 0;
}
