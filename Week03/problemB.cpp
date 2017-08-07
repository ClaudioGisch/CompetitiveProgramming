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

//The Lonesome Cargo Distributor | UVa Id:10172
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1113

bool allDelivered(queue<int> stations[]){
    bool result = true;
    for(int i = 0; i < stations->size(); i++){
       if(!stations[i].empty()){
            result = false;
       }
    }
    return result;
}

int main(){
    int sets;
    cin >> sets;
    for(int p = 0; p < sets; p++){
        int time = 0;
        int n, s, q;
        cin >> n >> s >> q;
        queue<int> stations[n];
        stack<int> carrier;
        for(int q = 0; q < n; q++){
            int cq; //current queue
            cin >> cq;
            for(int r = 0; r < cq; r++){
                int aux;
                cin >> aux;
                stations[r].push(aux);
            }
        }
        int station = 0;
        while(!allDelivered(stations)){
            time += 2;
            while(stations[station].size() < q && !carrier.empty()){
                if(!carrier.top() == (station + 1)){
                    stations[station].push(carrier.top());
                }
                carrier.pop();
                time++;
            }
            while(carrier.size() < s && !stations[station].empty()){
                carrier.push(stations[station].front());
                stations[station].pop();
                time++;
            }
            if(station < n-1){
                station++;
            }
            else{
                station = 0;
            }
        }
        cout << time << endl;

    }
    return 0;
}
