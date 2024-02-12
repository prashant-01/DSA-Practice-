#include<bits/stdc++.h>
using namespace std;

long long solve(vector<long long>x , vector<long long>y , vector<vector<long long>>&dp , vector<bool>vis , long long cityA , long long cityB , long long e , long long k){
    if(cityB == e){
        return (cityA <= k && cityB <= k) ? 0 : (abs(x[cityA]-x[cityB]) + abs(y[cityA]-y[cityB]));
    }
    if(dp[cityA][cityB] != -1)return dp[cityA][cityB];

    long long mn=INT_MAX;
    for(long long i=1 ;i < x.size() ;i++){
        if(vis[i])continue;
        vis[cityB]=true;
        long long ans = (cityA <= k && cityB <= k) ? 0 : abs(x[cityA]-x[cityB]) + abs(y[cityA]-y[cityB]);
        mn = min(mn , solve(x , y , dp , vis , cityB , i , e , k) + ans);
        //vis[cityB]=false;
    }
    return dp[cityA][cityB] = mn;
}
int main(){
    long long t;cin >> t;
    while(t--){
        long long n,k,a,b,mn=INT_MAX;cin>>n>>k>>a>>b;
        vector<long long>x(n+1) , y(n+1);
        vector<bool>vis(n+1 , false);vis[a]=true;
        vector<vector<long long>>dp(n+1 , vector<long long>(n+1 , -1));
        for(long long i=1;i<=n;i++){
            cin >> x[i] >> y[i];
        }
        if(n == 2){
            long long ans = (a <= k && b <= k) ? 0 : (abs(x[a]-x[b]) + abs(y[a]-y[b]));
            cout << ans << endl;continue;
        }
        for(long long i=1 ;i <= n ;i++){
            long long ans = solve(x , y , dp , vis , a , i , b , k);
            //cout << ans << " ";
            mn = min (mn , ans);
        }
        cout << mn << endl;
    }
}