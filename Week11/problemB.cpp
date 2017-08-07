#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Spreading The News | UVa Id:924
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=865

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

vec<vec<uint>> G;
vec<bool> marked;
uint N, M;

uint max_boom, boom_day;

void bfs(uint s) {
    marked.assign(N, false);
    marked[s] = true;

    queue<uint> q, wavefront;
    wavefront.push(s);

    max_boom = boom_day = 0;

    uint day = 1;
    while(!wavefront.empty()) {
        while(!wavefront.empty()) {
            q.push(wavefront.front());
            wavefront.pop();
        }
        wavefront = queue<uint>();
        while(!q.empty()) {
            uint u = q.front(); q.pop();
            fore(v, G[u]) {
                if(!marked[v]) {
                    marked[v] = true;
                    wavefront.push(v);
                }
            }
        }

        if(max_boom < wavefront.size()) {
            max_boom = wavefront.size();
            boom_day = day;
        }
        day++;
    }
}

int main() {
    while (true) {
        cin >> N;
        if(cin.eof()) return 0;
        G.clear();
        G.resize(N);
        foru(u, 0, N) {
            uint n;
            cin >> n;
            foru(j, 0, n) {
                uint v;
                cin >> v;
                G[u].push_back(v);
            }
        }
        uint Q;
        cin >> Q;
        foru(q, 0, Q) {
            uint s;
            cin >> s;
            bfs(s);
            if(max_boom == 0)
                cout << max_boom << endl;
            else
                cout << max_boom << " " << boom_day << endl;
        }
    }

    return 0;
}
