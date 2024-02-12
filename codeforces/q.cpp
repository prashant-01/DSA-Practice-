 #include<bits/stdc++.h>
 using namespace std;

 int solve(int n , vector<int>v){
    int count0 = 0 , count1=0;
    int mx=INT_MAX;
    for(int i=0 ; i<n;i++){
        if(v[i] == 1){
            mx=max(mx , count0);
            count0=0;
            count1++;
        }
        else count0++;
    }
    return mx + count1;
 }

 int main(){
    int n;cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << solve(n , v);
 }