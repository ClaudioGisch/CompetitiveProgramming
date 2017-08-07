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

//Throwing cards away I | UVa Id:10935
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1876

int main(){
    int n;
    while(cin >> n && n != 0){
        queue<int> deck;
        for(int i = 1; i <= n; i++){
            deck.push(i);
        }
        cout << "Discarded cards:";
        while(deck.size() > 1){
            cout << " " << deck.front();
            deck.pop();
            if(deck.size() > 1){
                cout << ",";
            }
            deck.push(deck.front());
            deck.pop();
        }
        cout << endl << "Remaining card: " << deck.front() << endl;
    }
    return 0;
}

