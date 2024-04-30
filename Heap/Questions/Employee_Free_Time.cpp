#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>ans;
    auto Compare = [](pair<int , int>a , pair<int , int>b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    };
    priority_queue<pair<int , int> , vector<pair<int , int>> , decltype(Compare)>minHeap(Compare);
    vector<vector<vector<int>>> v = { { {1,3} , {6,7} } , { {2,4} }  , { {2,5} , {9,12} } };
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            minHeap.push({ v[i][j][0] , v[i][j][1] });
        }
    }
    pair<int , int>p = minHeap.top();
    minHeap.pop();
    int x=p.first , y=p.second;
    while(!minHeap.empty()){
        p = minHeap.top();
        minHeap.pop();
        if(p.first < y)y=p.second;
        else{
            ans.push_back({y , p.first});
            x=p.first , y=p.second;
        }
    }
    for(int i=0 ; i<ans.size() ; i++)
        cout << ans[i][0] << " " << ans[i][1] << endl;
}