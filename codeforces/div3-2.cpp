#include<bits/stdc++.h>
using namespace std;
long long minDis(vector<long long>x , vector<long long>y , long long city , long long k){
    long long mn=INT_MAX;
    for(int i=1 ; i<= k ;i++){
        long long ans1 = (long long) abs(x[i]-x[city]) + (long long) abs(y[i]-y[city]);
        mn=min(mn , ans1);
    }
    return mn;
}
bool solve1(int ind , long long x , int k , vector<long long>v , vector<long long>&t , vector<vector<long long>>&dp){
    if(x == 0){
        if(t.size() == k)return 1;
        return 0;
    }
    if(ind == 0)return 0;
    if(dp[ind][x] != -1)return dp[ind][x];

    bool caseA = solve1(ind-1 , x , k , v , t , dp);
    t.push_back(v[ind]);
    bool caseB = solve1(ind-1 , x-v[ind] , k , v , t , dp);
    t.pop_back();

    return dp[ind][x] = (caseA || caseB);
}
void solve(){
    int n,k,x ; cin >> n >> k >> x;
    vector<long long>v(n+1) , t;
    for(int i=1 ; i<=n ; i++)v[i]=i;
    vector<vector<long long>>dp(n+1 , vector<int>(x+1 , -1));
    if(solve1(n , x , k , v , t , dp))cout << "YES" << endl;
    return cout << "NO" << endl;
}
int main(){
    int t;cin >> t;
    while(t--){
        solve();
    }
}