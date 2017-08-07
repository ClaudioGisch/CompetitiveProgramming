#include <bits/stdc++.h>
using namespace std;

//CODED BY https://github.com/famibica
//Where Are My Genes | UVa Id:1271
//https://www.urionlinejudge.com.br/judge/en/problems/view/1271

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
    std::vector<int> gene;
    int posA, posB, changes, numGenes, genoma = 1;
    while(true)
    {
        cin >> numGenes;
        if(numGenes == 0) break;
        cout << "Genome " << genoma << endl;
        cin >> changes;

        gene.resize(numGenes);
        iota(gene.begin(), gene.end(), 1);

        while(changes--)
        {
          cin >> posA >> posB;
          posA--;
          posB--;

          //reverse(gene.begin() + posA, gene.end() + posB);
          while(posA < posB){
            swap(gene[posA], gene[posB]);
            ++posA;
            --posB;
          }
        }

        int numLeituras;
        cin >> numLeituras;
        while(numLeituras--)
        {
          int busca;
          cin >> busca;
          auto resultado = find(gene.begin(), gene.end(), busca);
          cout << (resultado - gene.begin() + 1) << endl;
        }
        genoma++;
    }
    return 0;
}