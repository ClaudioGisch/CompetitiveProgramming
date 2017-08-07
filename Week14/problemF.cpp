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

#define MAX 110

using namespace std;

//NOT TOTALLY SOLVED
//The Chamber of Secrets | URI Id:1839
//https://www.urionlinejudge.com.br/judge/en/problems/view/1839

int main(){
    int n, m;
    cin >> n >> m;
    char input;
    string rest;
    int A[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input;
            if(input == '#'){
                A[i][j] = 1;
            }else{
                A[i][j] = 0;
            }
        }
        getline(cin, rest);
    }
    int xa, ya, xb, yb;
    while(cin >> xa >> ya >> xb >> yb){
        int sum = 0;
        for(int i = xa-1; i < xb-1; i++){
            for(int j = ya-1; j < yb-1; j++){
                sum += A[i][j];
            }
        }
        int total = (xb - xa) * (yb - ya);
        long result = 1;
        long div;
        for(int i = total; i > sum; i--){
            result = (result * i)%1000000007;
        }
        for(int i = 0; i < (total-sum); i++){
            div = (div * i)%1000000007;
        }
        cout << result;
    }


    return 0;
}
