#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Go-- | URI Id:2241
//https://www.urionlinejudge.com.br/judge/en/problems/view/2241

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

uint black[500][500], white[500][500];
uint b_SAT[501][501], w_SAT[501][501];

uint area_black(uint i, uint j, uint si, uint sj) {
    return b_SAT[i+si][j+sj] - b_SAT[i+si][j] - b_SAT[i][j+sj] + b_SAT[i][j];
}

uint area_white(uint i, uint j, uint si, uint sj) {
    return w_SAT[i+si][j+sj] - w_SAT[i+si][j] - w_SAT[i][j+sj] + w_SAT[i][j];
}

int main() {
    uint N, P;
    cin >> N >> P;
    memset(black, 0, sizeof(uint) * 500 * 500);
    memset(white, 0, sizeof(uint) * 500 * 500);
    memset(b_SAT, 0, sizeof(uint) * 500 * 500);
    memset(w_SAT, 0, sizeof(uint) * 500 * 500);
    foru(p, 0, P) {
        uint i, j;
        cin >> i >> j;
        black[i-1][j-1] = 1;
    }
    foru(p, 0, P) {
        uint i, j;
        cin >> i >> j;
        white[i-1][j-1] = 1;
    }
    foru(i, 0, N)
        foru(j, 0, N) {
            b_SAT[i+1][j+1] = black[i][j] - b_SAT[i][j] + b_SAT[i+1][j] +
                b_SAT[i][j+1];
            w_SAT[i+1][j+1] = white[i][j] - w_SAT[i][j] + w_SAT[i+1][j] +
                w_SAT[i][j+1];
        }

    uint count_w = 0, count_b = 0;
    foru(i, 0, N) {
        foru(j, 0, N) {
            for(uint n = 1; ((i + n) <= N) && ((j + n) <= N); n++) {
                uint a_black = area_black(i, j, n, n);
                uint a_white = area_white(i, j, n, n);
                if(a_black && !a_white)
                    count_b++;
                if(!a_black && a_white)
                    count_w++;
            }
        }
    }
    cout << count_b << " " << count_w << endl;

    return 0;
}