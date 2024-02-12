#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

void solve(){
    long long n , k , x;cin >> n >> k >> x;
    long long a = k*(k-1)/2;
    if(a >= x){
        cout << "NO" << endl;
        return;
    }
    long long c = n-k+1;
    long long b = n*(n+1)/2 - c*(c+1)/2;
    bool op1 = (x-a <= n && x-a >= k) ? true : false;
    bool op2 = (x-b <= (n-k+1)) ? true : false;
    if(op1 || op2)cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TestCases;cin >> TestCases;
    while(TestCases--){
        solve();
    }
}