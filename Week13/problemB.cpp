#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/mhbackes
//Huaauhahhuahau | URI Id:2242
//https://www.urionlinejudge.com.br/judge/en/problems/view/2242

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

bool is_palindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i++] != s[j--])
            return false;
    }
    return true;
}

bool is_vowel(char c) {
    return c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string s, t, r;
    cin >> s;
    transform(s.beg(), s.end(), back_inserter(t), ::tolower);
    copy_if(t.beg(), t.end(), back_inserter(r), is_vowel);
    cout << (is_palindrome(r) ? "S" : "N") << endl;
    return 0;
}