#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Reverse and Add | UVa Id:10018
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=959

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

unsigned reverse(unsigned i) {
    string s = to_string(i);
    reverse(s.beg(), s.end());
    return stoul(s, nullptr, 10);
}

bool is_palindrome(unsigned x) {
    string s = to_string(x);
    uint i = 0, j = s.size()-1;
    while(i < j) {
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}

int main() {
    uint N;
    cin >> N;
    foru(n, 0, N) {
        uint x;
        cin >> x;

        uint num_it = 0;
        do {
            uint y = reverse(x);
            x += y;
            num_it++;
         } while(!is_palindrome(x));
        cout << num_it << " " << x << endl;
    }
    return 0;
}