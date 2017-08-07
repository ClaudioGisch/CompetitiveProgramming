#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Merging Trees | URI Id:2240
//https://www.urionlinejudge.com.br/judge/en/problems/view/2240
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

vec<int> ll, lc, rr, rc;

uint max_size = 0;
void longest_seq(vec<int> &c, vec<int> &s, uint root, uint sum) {
    max_size = max(max_size, sum+1);
    if(c[root] != -1)
        longest_seq(c, s, c[root], sum + 1);
    if(s[root] != -1)
        longest_seq(c, s, s[root], 0);
}

uint root_long_seq(vec<int> &c, uint root) {
    uint sum = 1;
    while(c[root] != -1) {
        sum++;
        root = c[root];
    }
    return sum;
}

int main() {
    uint lN, rN;
    cin >> lN;
    ll.assign(lN, -1);
    lc.assign(lN, -1);
    foru(n, 0, lN) {
        int i, l, c;
        cin >> i >> l >> c;
        i--; l--; c--;
        ll[i] = l;
        lc[i] = c;
    }
    cin >> rN;
    rr.assign(rN, -1);
    rc.assign(rN, -1);
    foru(n, 0, rN) {
        int i, r, c;
        cin >> i >> c >> r;
        i--; r--; c--;
        rr[i] = r;
        rc[i] = c;
    }

    max_size = 0;
    longest_seq(lc, ll, 0, 0);
    uint lseq = max_size;
    max_size = 0;
    longest_seq(rc, rr, 0, 0);
    uint rseq = max_size;
    uint lrootseq = root_long_seq(lc, 0);
    uint rrootseq = root_long_seq(rc, 0);

    uint max_seq = max(min(lseq, rrootseq), min(rseq, lrootseq));
    cout << lN + rN - max_seq << endl;

    return 0;
}