#include<bits/stdc++.h>
using namespace std;

bool countCows(vector<int>v , int m , int dis){
    int cows=1 , position=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i] - position >= dis){
            cows++;
            position=v[i];
        }
        if(cows==m)return true;
    }
    return false;
}
int minDis(vector<int>v , int m){
    sort(v.begin() , v.end());
    int l=v[0];
    int h=v[v.size()-1]-v[0],mid,ans=-1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(countCows(v,m,mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;
}
int main(){
    int n,m;cin >> n;cin>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << minDis(v,m);
}