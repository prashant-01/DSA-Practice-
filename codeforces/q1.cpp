#include<bits/stdc++.h>
using namespace std;

int solve(int n , vector<int>v){
    int sum = accumulate(v.begin() , v.end() , 0);
    if(sum <= 0)return 0;
    int count=0;
    int mx=INT_MIN;
    for(int i=0 ; i<n;i++){
        if(v[i] < 0){
            mx=max(mx , count);
            count=0;
        }
        else count+=v[i];
    }
    if(count > 0)mx=max(mx , count);
    return mx;
    // vector<int>prefix(n , 0);
    // if(v[0] > 0)prefix[0]=v[0];
    
    // for(int i=1;i<n;i++){
    //     int currSum=prefix[i-1]+v[i];
    //     if(currSum>=0){
    //         prefix[i]=currSum;
    //         maxSum=max(maxSum , prefix[i]);
    //     }else prefix[i]=0;
    // }
    // return maxSum;
}

int main(){
    int n;cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << solve(n , v);
}