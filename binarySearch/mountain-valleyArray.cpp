#include<bits/stdc++.h>
using namespace std;
int maxOfMountainArray(vector<int>nums){
    int l=0,r=nums.size()-1,mid,maxVal=INT_MIN;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid] < nums[mid+1])l=mid+1;
        else if(nums[mid] >= nums[mid+1]){
            if(nums[mid] > maxVal){
                maxVal=nums[mid];
            }
            r=mid-1;
        }
    }
    return maxVal;
}

int minOfValleyArray(vector<int>nums){
    int l=0,r=nums.size()-1,mid,minVal=INT_MAX;
    while(l<=r){
        mid=l+(r-l)/2;
        if(nums[mid] > nums[mid+1])l=mid+1;
        else if(nums[mid] <= nums[mid+1]){
            if(minVal > nums[mid])minVal=nums[mid];
            r=mid-1;
        }
    }
    return minVal;
}
int main(){
    vector<int>v(8);
    for(int i=0;i<v.size();i++)cin >> v[i];
    // int ansMax = maxOfMountainArray(v);
    // cout <<"MAX VALUE " << ansMax << "\n";
    int ansMin = minOfValleyArray(v);
    cout <<"MIN VALUE " << ansMin;
}