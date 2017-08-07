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

//Sending email | UVa Id:10986
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1927

vector< vector< pair<int,int> > > g;

int dijkstra(int a, int b, int n)
{
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
    vector<int> d(n, -1);
    pair<int,int> p; int v,w;
    q.push( make_pair(0,a) );
    while (!q.empty()){
        p = q.top(); q.pop();
        v = p.second;
        w = p.first;
        if ( d[v] != -1 ) continue;
        if (v == b) return w;
        d[v] = w;

        for (int i = 0; i < g[v].size(); ++i)
        if ( d[ g[v][i].first ] == -1 ){
            q.push( make_pair( w+g[v][i].second, g[v][i].first ) );
        }
    }
    return -1;
}

int main(){
    int cases, n, m, s, t, result;
    int v1, v2, w;
    cin >> cases;
    for(int c = 0; c < cases; c++){
        cin >> n >> m >> s >> t;
        g.resize(n);
        for(int i = 0; i < m; i++){
            cin >> v1 >> v2 >> w;
            g[v1].push_back(make_pair(v2, w));
            g[v2].push_back(make_pair(v1, w));
        }

        result = dijkstra(s, t, n);
        if(result == -1){
            cout << "Case #" << c+1 << ": unreachable" << endl;
        }else{
            cout << "Case #" << c+1 << ": " << result << endl;
        }
        g.clear();
    }
    return 0;
}
