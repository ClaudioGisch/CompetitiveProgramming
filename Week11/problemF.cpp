#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Risk | UVa Id:12264
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3416

typedef unsigned uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

const uint UINF = numeric_limits<uint>::max();
const int PINF = numeric_limits<int>::max();
const int NINF = numeric_limits<int>::min();
const ulong ULINF = numeric_limits<ulong>::max();
const long LPINF = numeric_limits<long>::max();
const long LNINF = numeric_limits<long>::min();

#define beg begin
#define xx first
#define yy second
#define vec vector
#define fori(var,from,to)   for (int var = from; var < to; var++)
#define foru(var,from,to)   for (uint var = from; var < to; var++)
#define forid(var,from,to)  for (int var = from; var > to; var--)
#define forud(var,from,to)  for (uint var = from; var > to; var--)
#define fore(var,cont)      for (auto var : cont)

template<typename T>
using min_queue = priority_queue<T, vec<T>, greater<T>>;
template<typename T>
using max_queue = priority_queue<T, vec<T>, less<T>>;

#define w xx
#define n yy
typedef pair<uint, uint> Edge;

vec<vec<Edge>> G;
vec<uint> dist;
uint N, M;

void dijkstra(uint s, uint t) {
    dist.assign(N, UINF);
    dist[s] = 0;
    priority_queue<Edge, vec<Edge>, greater<Edge>> q;
    q.push(Edge(0, s));
    while(!q.empty()) {
        Edge front = q.top(); q.pop(); 
        uint d = front.w, u = front.n;
        if(d > dist[u]) continue;
        if(u == t) return;
        for(uint j = 0; j < G[u].size(); j++) {
            Edge e = G[u][j];
            if(dist[u] + e.w < dist[e.n]) {
                dist[e.n] = dist[u] + e.w;
                q.push(Edge(dist[e.n], e.n));
            }
        }
    }
}

int main() {
    uint test = 1;
    while (true) {
        G.clear();
        G.resize(20);
        foru(u, 0, 19) {
            N = 20;
            uint n;
            cin >> n;
            if(cin.eof()) return 0;
            foru(j, 0, n) {
                uint v;
                cin >> v;
                v--;
                Edge e0, e1;
                e0.n = v, e0.w = 1;
                e1.n = u, e1.w = 1;
                G[u].push_back(e0);
                G[v].push_back(e1);
            }
        }
        uint Q;
        cin >> Q;
        cout << "Test Set #" << test++ << endl;
        foru(q, 0, Q) {
            uint s, t;
            cin >> s >> t;
            printf("%2d to %2d: ", s, t);
            s--, t--;
            dijkstra(s, t);
            cout << dist[t] << endl;
        }
        cout << endl;
    }

    return 0;
}
