#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int solve1(int ind , int k , unordered_set<int>s , vector<vector<int>>v  , vector<vector<int>>&dp){
    // if(s.size() == k)return 0;
    if(ind == v.size()){
        if(s.size() < k)return 1;
        return 0;
    }
    if(dp[ind][s.size()])return dp[ind][s.size()];

    int op1 = solve1(ind+1, k , s , v , dp);
    for(int i=0 ; i<v[ind].size() ; i++)s.insert(v[ind][i]);
    int op2 = solve1(ind+1, k , s , v , dp);

    return dp[ind][s.size()] = op1 || op2;
}
void solve(){
    int n;cin >> n ;
    unordered_set<int>s , s1;
    vector<vector<int>>v , dp(n , vector<int>(51 , 0));
    while(n--){
        int n1;cin >> n1;
        vector<int>t(n1);
        for(int i=0 ; i<n1 ; i++){
            cin >> t[i];
            s1.insert(t[i]);
        }
        v.push_back(t);
    }
    int l=s1.size();int mx=INT_MIN;
    solve1(0, l , s , v , dp);
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<l ; j++){
            if(dp[i][j])mx=max(mx , j);
        }
    }
    mx = mx == INT_MIN ? 0 : mx;
    cout << mx << endl;
    return;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TestCases;cin >> TestCases;
    while(TestCases--){
        solve();
    }
}