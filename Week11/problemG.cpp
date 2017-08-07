#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/famibica
//Vacation| UVa Id:10192
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1133

typedef unsigned uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

#define beg begin
#define xx first
#define yy second
#define vec vector
#define fori(var,from,to)   for (int var = from; var < to; var++)
#define foru(var,from,to)   for (uint var = from; var < to; var++)
#define forid(var,from,to)  for (int var = from; var > to; var--)
#define forud(var,from,to)  for (uint var = from; var > to; var--)
#define fore(var,cont)      for (auto var : cont)

int main() {
    string s, t;
    int cases = 0;
    while(true) {
        getline(cin, s);
        if(s == "#") break;
        getline(cin, t);
        if(cin.eof()) break;
        unsigned S = s.size(), T = t.size();
        unsigned A[S+1][T+1];
        memset(A[0], 0, (S+1)*(T+1)*sizeof(unsigned));
        foru(i, 1, S+1)
            foru(j, 1, T+1) {
                if(s[i-1] == t[j-1])
                    A[i][j] = A[i-1][j-1] + 1;
                else
                    A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
        cases++;
        cout << "Case #" << cases << ": you can visit at most " << A[S][T] << " cities."<< endl;
    }
    return 0;
}