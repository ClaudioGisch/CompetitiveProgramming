#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>

using namespace std;

//I Can Guess the Data Structure! | UVa Id:11995
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=3146

int main(){
    int n;
    while(cin >> n){
        int op, num;
        stack<int> stacking;
        queue<int> queueing;
        priority_queue<int> pri_queue;
        bool isStack = true;
        bool isQueue = true;
        bool isPriQueue = true;
        for(int i = 0; i < n; i++){
            cin >> op >> num;
            if(op == 1){
                stacking.push(num);
                queueing.push(num);
                pri_queue.push(num);
            }else{
                if(stacking.empty()){
                   isStack = false;
                }else{
                    if(stacking.top() != num){
                        isStack = false;
                    }
                    stacking.pop();
                }
                if(queueing.empty()){
                   isQueue = false;
                }else{
                    if(queueing.front() != num){
                        isQueue = false;
                    }
                    queueing.pop();
                }
                if(pri_queue.empty()){
                   isPriQueue = false;
                }else{
                    if(pri_queue.top()!= num){
                        isPriQueue = false;
                    }
                    pri_queue.pop();
                }
            }
        }
        if((isStack && isQueue) || (isStack && isPriQueue) || (isPriQueue && isQueue) || (isStack && isQueue && isPriQueue)){
            cout << "not sure" << endl;
        }else{
            if(isStack){
               cout << "stack" << endl;
            }else{
                if(isQueue){
                    cout << "queue" << endl;
                }else{
                    if(isPriQueue){
                        cout << "priority queue" << endl;
                    }else{
                        cout << "impossible" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
