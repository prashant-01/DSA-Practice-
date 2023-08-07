#include<bits/stdc++.h>
using namespace std;

// applying bs on a subarray
int binarySearch(vector<int>v , int l ,int h , int target){
    int mid=-1;
    while(l<=h){
        mid=l+(h-l)/2;
        if(v[mid] == target)return mid;
        else if(v[mid] < target)l=mid+1;
        else h=mid-1;
    }
    return mid;
}
int expSearch(vector<int>v , int target){
    int i , n=v.size()-1;
    if(target == v[0])return 0;
    else{
        i=1;
        while(i<v.size() && v[i] <= target)i*=2;
    }
    return binarySearch(v, i/2 , min(i,n) , target);
}

int main(){
    vector<int>v = {1,3,5,6,7,9,10,11,15,18,21,25,29,34,35,39,41,45,49,50,54};
    int target;cin >> target;
    cout << expSearch(v,target);
}