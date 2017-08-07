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
#define MAX 200

using namespace std;

//Bicoloring | UVa Id:10004
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=945

int color[MAX];
vector<int> graph[MAX];

bool paint(int node, int c){
    if(color[node] == 0){
        color[node] = c;
        if(c == 1){
            c = 2;
        }else{
            c = 1;
        }
        while(!graph[node].empty()){
            if(paint(graph[node].back(), c) == false){
                return false;
            }
            graph[node].pop_back();
        }
    }else{
        if(color[node] != c){
            return false;
        }
    }
    return true;
}

int main(){
    int n, l;
    cin >> n;
    while(n != 0){
        cin >> l;
        for(int i = 0; i < n; i++){
            color[i] = 0;
            graph[i].clear();
        }
        int a, b;
        for(int i = 0; i < l; i++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if(paint(0, 1)){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
        cin >> n;
    }

    return 0;
}
