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

using namespace std;

//Expert Enough? | UVa Id:1237
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3678

class Maker{
    string name;
    int lowest;
    int highest;
public:
    void set_data(string new_name, int new_lowest, int new_highest){
        name = new_name;
        lowest = new_lowest;
        highest = new_highest;
    }
    bool between_values(int price){
        return ((lowest <= price) && (price <= highest));
    }
    string get_maker(){
        return name;
    }
};

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int d;
        cin >> d;
        Maker data[d];
        for(int j = 0; j < d; j++){
            string maker;
            int lowest;
            int highest;
            cin >> maker >> lowest >> highest;
            data[j].set_data(maker, lowest, highest);
        }
        int query;
        cin >> query;
        for(int j = 0; j < query; j++){
            int price;
            stack<Maker> result;
            cin >> price;
            for(int k = 0; k < d; k++){
                if(data[k].between_values(price)){
                    result.push(data[k]);
                }
            }
            if(result.empty() || (result.size() > 1)){
                cout << "UNDETERMINED" << endl;
            }
            else{
                Maker maker = result.top();
                cout << maker.get_maker() << endl;
            }
        }
        if(i != t-1){
            cout << endl;
        }
    }
    return 0;
}
