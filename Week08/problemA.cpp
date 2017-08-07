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
#include <unordered_map>
#include <vector>

using namespace std;

//Expensive subway | UVa Id:11710
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2757

struct compare{
    bool operator()(pair<int,int> l, pair<int, int> r){
        return l.first > r.first;
    }
};

int main(){
    int s, c; //stations and connections
    cin >> s >> c;
    while((s != 0) || (c != 0)){
        //input read
        unordered_map<string, int> dic;
        int connections[s][s];
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                connections[i][j] = 0;
            }
        }
        string city;
        string city2;
        int cost;
        for(int i = 0; i < s; i++){//stations
            cin >> city;
            dic[city] = i;
        }
        for(int i = 0; i < c; i++){//connections
            cin >> city >> city2 >> cost;
            if((cost < connections[dic[city]][dic[city2]]) || (connections[dic[city]][dic[city2]] == 0)){
                connections[dic[city]][dic[city2]] = cost;
                connections[dic[city2]][dic[city]] = cost;
            }
        }
        cin >> city; //Peter's city

        //solution
        if(s > c + 1){
            cout << "Impossible" << endl;
        }else{
            priority_queue<pair<int, int>, vector<pair<int,int>>, compare> pq;
            int sol[s];
            for(int i = 0; i < s; i++){
                sol[i] = 0;
            }
            sol[dic[city]] = 1;
            for(int i = 0; i < s; i++){
                if(connections[dic[city]][i] != 0){
                    pq.push(make_pair(connections[dic[city]][i], i));
                }
            }
            pair<int, int> ve; //pair vertex/edge
            int sum = 0;
            while(!pq.empty()){
                ve = pq.top();
                pq.pop();
                if(sol[ve.second] == 0){
                    sol[ve.second] = 1;
                    sum = sum + ve.first;
                    for(int i = 0; i < s; i++){
                        if(sol[i] == 0){
                            if(connections[ve.second][i] != 0){
                                pq.push(make_pair(connections[ve.second][i], i));
                            }
                        }
                    }
                }
            }
            bool possible = true;
            for(int i = 0; i < s; i++){
                if(sol[i] != 1){
                    possible = false;
                }
            }
            if(possible){
                cout << sum << endl;
            }else{
                cout << "Impossible" << endl;
            }
        }

        cin >> s >> c;
    }

    return 0;
}
