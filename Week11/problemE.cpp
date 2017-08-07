#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Jogo do Bicho | UVa Id:1483
//https://www.urionlinejudge.com.br/judge/pt/problems/view/1483

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

double bixo(double v, uint n, uint m) {
    string sn = to_string(n), sm = to_string(m);
    while(sn.size() < 4)
        sn = "0" + sn;
    while(sm.size() < 4)
        sm = "0" + sm;

    if(sn.substr(sn.size()-4, 4) == sm.substr(sm.size()-4, 4))
        return 3000 * v;

    if(sn.substr(sn.size()-3, 3) == sm.substr(sm.size()-3, 3))
        return 500 * v;

    if(sn.substr(sn.size()-2, 2) == sm.substr(sm.size()-2, 2))
        return 50 * v;

    uint n2 = stoul(sn.substr(sn.size()-2, 2), nullptr, 10) + 3;
    uint m2 = stoul(sm.substr(sm.size()-2, 2), nullptr, 10) + 3;

    if(n2 / 4 == m2 / 4)
        return 16 * v;

    return 0;
}

int main() {
    double V;
    uint N, M;
    while(true) {
        cin >> V >> N >> M;
        if(V == 0 && N == 0 && M == 0) break;
        printf("%.2lf\n", bixo(V, N, M));
    }
    return 0;
}