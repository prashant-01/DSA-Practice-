#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&v , int index , vector<vector<int>>&ans , vector<int>&num , unordered_map<int , int>&mp , 
    unordered_map<int , int>&mp1){
    if(index == v.size()){
        ans.push_back(num);
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i] == mp[index] || mp1.find(v[i]) != mp1.end())continue;
        mp1[v[i]]=index;
        num.push_back(v[i]);
        solve(v , index + 1 , ans , num , mp , mp1);
        num.pop_back();
    }
}
int main(){
    vector<int>v={0,0,1, 1} , num;
    vector<vector<int>>ans;
    unordered_map<int , int>mp , mp1;
    for(int i=0;i<v.size();i++)mp[i]=v[i];
    solve(v , 0 , ans , num , mp , mp1);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}