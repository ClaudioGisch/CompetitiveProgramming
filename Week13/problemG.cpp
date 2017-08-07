#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Dating On-Line | URI Id:12348
//https://www.urionlinejudge.com.br/judge/en/problems/view/2348

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

double area_tri(double a, double b, double deg) {
    return a * b * sin(deg) / 2;
}

int main() {
    uint N;
    cin >> N;
    double deg = 2 * M_PI / N;
    vec<uint> s(N), r(N);
    foru(n, 0, N) {
        cin >> s[n];
    }
    sort(s.beg(), s.end());

    uint i = 0;
    for(; i < (N/2+N%2); i++) {
        r[i] = s[2*i];
    }
    uint j = N-1-(N%2);
    for(; i < N; i++) {
        r[i] = s[j];
        j -= 2;
    }

    double area = 0.0;
    foru(i, 1, N) {
        area += area_tri(r[i], r[i-1], deg);
    }
    area += area_tri(r[0], r[N-1], deg);
    printf("%.3lf\n", area);

    return 0;
}