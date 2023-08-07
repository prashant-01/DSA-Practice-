#include<bits/stdc++.h>
using namespace std;
set<pair<int , int>> kDiffPairs(vector<int>v , int k){
    set<pair<int , int>>ans;
    sort(v.begin() , v.end());
    int i=0,j=1;
    while(j<v.size()){
        int diff=v[j]-v[i];
        if(diff==k){
            if(i!=j){
                ans.insert({v[i],v[j]});//O(logn) insertion in Set as it uses Red-Black BST 
                i++;j++;
            }else{
                i++;j++;
            }
        }
        else if(diff < k)j++;
        else i++;
    }
    return ans;
}
int main(){
    vector<int>v(8);
    for(int i=0;i<8;i++)cin >> v[i];
    int k;cin >> k;
    set<pair<int , int>>ans;
    ans=kDiffPairs(v,k);
    //cout << ans.size();
    for(auto i : ans)cout << i.first << " " << i.second << " ";
    return 0;
}