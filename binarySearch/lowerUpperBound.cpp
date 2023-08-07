#include<bits/stdc++.h>
using namespace std;
void lowerBound (vector<int>v , int k){
    int l=0,r=v.size()-1,mid,ans=v[v.size()-1];
    while(l<=r){
        mid=l+(r-l)/2;
        if(v[mid]>=k){
            ans=v[mid];
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << "Lower Bound " << ans;
}

void upperBound (vector<int>v , int k){
    int l=0,r=v.size()-1,mid,ans=v[v.size()-1];
    while(l<=r){
        mid=l+(r-l)/2;
        if(v[mid]>k){
            ans=v[mid];
            r=mid-1;
        }
        else l=mid+1;
    }
    cout << "Upper Bound " << ans;
}
int main(){
    vector<int>v(8);
    for(int i=0;i<8;i++)cin >> v[i];
    int k;
    int n=5;
    while(n--){
        cin >> k;
        lowerBound(v,k);
        upperBound(v,k);
    }
    
}