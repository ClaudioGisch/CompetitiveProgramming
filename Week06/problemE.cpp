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

//Dividing coins | UVa Id:562
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=503
int main(){
    int n, num_coins;
    cin >> n;
    while(n > 0){
        cin >> num_coins;
        int coins[num_coins];
        int sum = 0;
        for(int i = 0; i < num_coins; i++){
            cin >> coins[i];
            sum += coins[i];
        }
        vector<int> coinsDiv((sum/2)+1, 0);
        for(int i = 0; i < num_coins; i++){
            for(int j = sum/2; j >= coins[i]; j--){
                coinsDiv[j] = coinsDiv[j] || (coins[i] == j) || coinsDiv[j-coins[i]];
            }
        }
        int i = sum/2;
        while(i > 0 && coinsDiv[i] == 0){
            i--;
        }
        cout << (sum - (2*i)) << endl;
        n--;
    }
    return 0;
}
