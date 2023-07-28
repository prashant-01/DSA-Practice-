#include<bits/stdc++.h>
using namespace std;
int maxOfRotatedSortedArray(vector<int> nums){
    int l=0,r=nums.size()-1,mid,maxVal=INT_MIN;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid] > maxVal){
            maxVal=nums[mid];
        }
        else if(nums[mid] >= nums[l])l=mid+1;
        else r=mid-1;
    }
    return maxVal;
}

int minOfRotatedSortedArray(vector<int> nums){
    int l=0,r=nums.size()-1,mid,minVal=INT_MAX;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid] < minVal){
            minVal=nums[mid];
        }
        else if(nums[mid] <= nums[r])r=mid-1;
        else l=mid+1;
    }
    return minVal;
}
int main(){
    vector<int>v(8);
    for(int i=0;i<v.size();i++)cin >> v[i];
    int ansMax = maxOfRotatedSortedArray(v);
    cout <<"MAX VALUE " << ansMax << "\n";
    int ansMin = minOfRotatedSortedArray(v);
    cout <<"MIN VALUE " << ansMin;
}