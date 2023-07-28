#include<bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int>nums , int target){//firstOccrence/lastOccurence/totalOccurence
    int r=nums.size()-1;
    int l=0,mid , index=-1;
    while(l<=r){
        //mid=l+(r-l)/2;
        mid=l+(r-l)/2;
        if(nums[mid]==target){
            index=mid;
            r=mid-1;
        }
        else if(nums[mid]<target)l=mid+1;
        else r=mid-1;
    }
    return index;
}
//similiarliy we can do for last occurence also 
// & by finding last & first occurence we can find the total occurence also (last - first occurence + 1)
//c++ has built-in function to calc it 
// auto firstOccurence=lower_bound(v.begin() , v.end() , target);
// auto lastOccurence=upper_bound(v.begin() , v.end() , target);
//firstOccurence-v.begin() is the index of first occurence
//lastOccurence-v.begin() is the index of last occurence
int main(){
    int target;
    vector<int>nums(8);
    for(int i=0;i<nums.size();i++)cin>>nums[i];
    //for(auto i:nums)cin>>i;
    cout << "Enter Target " ; cin >> target;
    cout << firstOccurence(nums , target);
}