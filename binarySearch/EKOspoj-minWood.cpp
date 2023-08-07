#include<bits/stdc++.h>
using namespace std;

bool countWood(vector<long long>v , long long m , long long height){
    long long woodLength=0;
    for(int i=0;i<v.size();i++){
        long long x=v[i]-height;
        woodLength += x>0?x:0;
    }
    if(woodLength >= m)return true;
    else return false;
}
int maxHeight(vector<long long>v,long long m){
    long long l=0,mid,ans=-1;
    long long h=*max_element(v.begin() , v.end());

    while(l<=h){
        mid=l+(h-l)/2;
        if(countWood(v , m , mid)){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return ans;
}
int main(){
    long long n,m;cin >> n;cin>>m;
    vector<long long>v(n);
    for(long long i=0;i<n;i++)cin >> v[i];
    cout << maxHeight(v,m);
}