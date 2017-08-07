#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

//Conformity | UVa Id:11286
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2261

int main(){
    int n;
    while(cin >> n && n != 0){
        typedef map<vector<int>, int> MapType;
        MapType mymap;
        int result[n] = {0};
        int cont = 0;
        for(int i = 0; i < n; i++){
            vector<int> vec;
            for(int j = 0; j < 5; j++){
                int aux;
                cin >> aux;
                vec.push_back(aux);
            }
            sort(vec.begin(), vec.end());
            MapType::iterator it = mymap.find(vec);
            if(it != mymap.end()){
                result[it->second] += 1;
            }else{
                mymap.insert({vec, cont});
                result[cont] += 1;
                cont++;
            }
        }
        int res = *max_element(result, result + n);
        int froshs = 0;
        for(int k = 0; k < n; k++){
            if(result[k] == res){
                froshs += res;
            }
        }
        cout << froshs << endl;
    }
    return 0;
}
