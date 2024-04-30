#include<bits/stdc++.h>
using namespace std;

// used two minHeaps one is keeping track of intervals and other one is keeping track of 
// min rooms required at current point of time
// we are pushing the ending time of the meeting in the rooms heap;
// if the start time of the current meeting is lesser than the top of rooms heap 
// it means that meeting which should end next is not ended yet hence we have to allocate new room for this meeting
// if the start time of the current meeting is greater than the top of rooms heap 
// it means the meeting whose ending time is denoted by rooms.top() is ended and it's room can be allocated to current meeting
// ! Time Complexity - O( n )
// ! Space Complexity - O( n )
int main(){
    auto Compare = [](pair<int , int>a , pair<int , int>b){
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    };
    priority_queue<pair<int , int> , vector<pair<int , int>> , decltype(Compare)>minHeap(Compare);
    priority_queue<int , vector<int> , greater<int>>rooms;
    vector<vector<int>>v = { {0,30} , {5,10} , {15,20} };
    for(int i=0 ; i<v.size() ; i++)
        minHeap.push({ v[i][0] , v[i][1] });
    pair<int , int>a;
    int ans=0;
    while(!minHeap.empty()){
        a = minHeap.top();
        minHeap.pop();
        if(rooms.empty() || a.first < rooms.top())
            rooms.push(a.second);
        else{
            rooms.pop();
            rooms.push(a.second);
        }
        ans = ans < rooms.size() ? rooms.size() : ans;
    }
    cout << ans;
}