#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int , vector<int> , greater<int>>minHeap;
    vector<int>v = { 1,8,3,5 };
    int ans=0;
    for(int i=0 ; i<v.size() ; i++)
        minHeap.push(v[i]);
    while(minHeap.size() > 1){
        if(minHeap.size() >= 2){
            int x = minHeap.top();
            minHeap.pop();
            int y = minHeap.top();
            minHeap.pop();
            minHeap.push(x+y);
            ans += x + y;
        }
    }
    cout << ans ;
}
