#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

#define MAX 101
#define MAXWEIGHT 500
using namespace std;

//Page Hopping | UVa Id:821
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=762

//Probably doesn't work because of the last número of float precision...

int dist[MAX][MAX];
int vertex[MAX];

int findPath(int i, int j, int k){

}

int main(){
    int a, b;
    int cont = 1;
    double result;
    cin >> a >> b;
    while((a != 0) && (b != 0)){
        for(int i = 0; i <= MAX; i++){
            for(int j = 0; j <= MAX; j++){
                dist[i][j] = MAXWEIGHT;
            }
            dist[i][i] = 0;
            vertex[i] = 0;
        }
        while((a != 0) && (b != 0)){
            dist[a][b] = 1;
            vertex[a] = 1;
            cin >> a >> b;
        }
        for(int k = 1; k <= MAX; k++){
            for(int i = 1; i <= MAX; i++){
                for(int j = 1; j <= MAX; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int totalSum = 0;
        int numV = 0; //number of vertices
        for(int i = 1; i <= MAX; i++){
            if(vertex[i] == 1){
                int partialSum = 0;
                for(int j = 1; j <= MAX; j++){
                     if(vertex[j] == 1){
                        partialSum = partialSum + dist[i][j];
                     }
                }
                if(partialSum < MAXWEIGHT){
                    totalSum = totalSum + partialSum;
                    numV = numV + 1;
                }
            }
        }
        result = double(totalSum)/double(numV*(numV-1));
        cout << "Case " << cont << ": average length between pages = ";
        printf("%.3f", result);
        cout << " clicks" << endl;
        cont++;
        cin >> a >> b;
    }

    return 0;
}
