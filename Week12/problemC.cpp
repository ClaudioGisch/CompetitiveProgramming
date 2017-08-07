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

#define MAX 100

using namespace std;

//Maximum GCD | UVa Id:11827
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2927

int gdc(int p, int q){
    if(q > p){
        return gdc(q,p);
    }
    if(q == 0){
        return p;
    }
    return gdc(q, (p%q));
}

int main(){
    int n, a;
    string line;
    cin >> n;
    getline(cin, line);

    for(int i = 0; i < n; i++){
        int numList[MAX];
        getline(cin, line);
        istringstream test(line);
        int j = 0;
        int maxGDC = 0;
        int resGDC;
        while(test >> a){
            numList[j] = a;
            j++;
        }
        for(int k = 0; k < j; k++){
            for(int l = k+1; l < j; l++){
                resGDC = gdc(numList[k], numList[l]);
                if(resGDC > maxGDC){
                    maxGDC = resGDC;
                }
            }
        }
        cout << maxGDC << endl;
    }

    return 0;
}
