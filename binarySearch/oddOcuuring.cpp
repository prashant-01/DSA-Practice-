#include<bits/stdc++.h>
using namespace std;
int oddOccuringElement(vector<int>v){
    int l=0,r=v.size()-1,mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if((mid-1) >=0 && v[mid] == v[mid-1]){
            if(mid%2==0)r=mid-1;
            else l=mid+1;
        }
        else if((mid+1) < v.size() && v[mid] == v[mid+1]){
            if(mid%2==0)l=mid+1;
            else r=mid-1;
        }
        else return v[mid];
    }
}
int main(){
    vector<int>v(7);
    for(int i=0;i<v.size();i++)cin>>v[i];
    cout << "Odd Occuring value is "<< oddOccuringElement(v);
}