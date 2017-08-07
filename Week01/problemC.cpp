#include<iostream>
#include<algorithm>
#define SQUARES 100

using namespace std;

//Snakes and Ladders | UVa Id:11459
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2454

int main(){
    int numTests;
    int fromTo[SQUARES];
    cin >> numTests;
    for(int k=0; k < numTests; k++){
        int i;
        int a, b, c;
        cin >> a >> b >> c;
        //from->to array for snakes and ladders
        for(i=0; i < SQUARES; i++){
            fromTo[i] = i+1;
        }
        int player[a];
        //initial position of players
        for(i=0; i < a; i++){
            player[i] = 1;
        }
        int f, t;
        //set snakes and ladders
        for(i=0; i < b; i++){
            cin >> f >> t;
            fromTo[f-1] = t;
        }
        int roll;
        i = 0;
        bool over = false;
        int index, movem;
        while(i < c){
            cin >> roll;
            if(!over){
                index = i % a;
                movem = player[index] + roll - 1;
                player[index] = fromTo[movem];
                if(player[index] >= 100){
                    player[index] = 100;
                    over = true;
                }
            }
            i++;
        }
        for(i=0; i < a; i++){
            cout << "Position of player " << i+1 << " is " << player[i] << "." << endl;
        }
    }
    return 0;
}