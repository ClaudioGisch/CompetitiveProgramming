#include<iostream>
#include<algorithm>

using namespace std;

//The 3n + 1 problem | UVa Id:100
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=36

int main(){
    int n, b, h, w;
    while(cin >> n >> b >> h >> w){
        int hotelPrice;
        int minPrice = b + 1;
        int totalPrice;
        int space;
        bool haveSpace;
        for(int i = 0; i < h; i++){
            cin >> hotelPrice;
            haveSpace = false;
            for(int j = 0; j < w; j++){
                cin >> space;
                if(space >= n){
                    haveSpace = true;
                }
            }
            if(haveSpace){
                totalPrice = n*hotelPrice;
                if(totalPrice < minPrice){
                    minPrice = totalPrice;
                }
            }
        }
        if(minPrice <= b){
            cout << minPrice << endl;
        }else{
            cout << "stay home" << endl;
        }
    }

    return 0;
}
