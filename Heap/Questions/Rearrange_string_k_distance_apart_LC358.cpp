#include<bits/stdc++.h>
using namespace std;
class Compare {
    public:
    bool operator()(pair<char , int>a , pair<char , int>b){
        return a.second < b.second;
    }
};


// The method uses a max heap to ensure that the character with the highest remaining frequency is selected next, 
// while a queue maintains the constraint of k distance to avoid repeating characters.
int main(){
    string s="aaadbbcc";
    string ans="";
    int k=1;
    unordered_map<char , int>count;
    for(auto c : s)count[c]++;
    queue<pair<char , int>>q;
    priority_queue<pair<char , int> , vector<pair<char , int>> , Compare>maxHeap;
    for(auto entry : count)maxHeap.push({ entry.first , entry.second });
    while(!maxHeap.empty()){
        pair<char , int>p = maxHeap.top();
        maxHeap.pop();
        ans.push_back(p.first);
        q.push({ p.first , p.second-1 });
        if(q.size() > k){
            p = q.front();
            q.pop();
            if(p.second)maxHeap.push(p);
        }
    }
    if(ans.size() == s.size())cout << ans;
    else cout << "noo"; 
}