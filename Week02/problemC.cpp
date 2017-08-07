#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

//Add All | UVa Id:10954
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1895

int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> numbers(n);
        for(int i = 0; i < n; i++){
            cin >> numbers[i];
        }
        int sum = 0;
        for(int i = 1; i < n; i++){
            int aux;
            sort(numbers.begin(), numbers.end());
            aux = *(numbers.begin()) + *(numbers.begin()+1);
            numbers.erase(numbers.begin());
            numbers.erase(numbers.begin());
            numbers.push_back(aux);
            sum += aux;
        }
        cout << sum << endl;
    }
    return 0;
}
