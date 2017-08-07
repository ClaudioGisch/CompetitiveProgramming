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

//Hanoi Tower Troubles Again! | UVa Id:10276
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1217

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num_pegs;
        cin >> num_pegs;
        stack<int> pegs[num_pegs];
        int ball = 1;
        int pos = 0;
        while(pos < num_pegs){
            if(!pegs[pos].empty()){
                float aux = sqrt((float) pegs[pos].top() + ball);
                float num = (int)aux;
                if(num - aux == 0.0){
                    pegs[pos].push(ball);
                    pos = 0;
                    ball++;
                }
                else{
                    pos++;
                }
            }
            else{
                pegs[pos].push(ball);
                pos = 0;
                ball++;
            }
        }
        cout << ball-1 << endl;
    }
    return 0;
}
