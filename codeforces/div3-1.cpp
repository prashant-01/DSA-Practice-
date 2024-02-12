#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

void solve(){
    int n,sum=0;cin >> n;
    vector<int>v(n);
    for(int i=0 ; i<n; i++)cin >> v[i];
    for(int i=0 ; i<n; i++)sum+=v[i];
    if(sum == 0){
        cout << "0" << endl;
    }
    else{
        if(n & 1){
            cout << "4" << endl;
            cout << "1 " << n-1 << endl;
            cout << "1 " << n-1 << endl;
            cout << n-1 << " " << n << endl;
            cout << n-1 << " " << n << endl;
        }
        else{
            cout << "2" << endl;
            cout << "1 " << n << endl;
            cout << "1 " << n << endl;
        }
    }
    return ;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int TestCases;cin >> TestCases;
    while(TestCases--){
        solve();
    }
}