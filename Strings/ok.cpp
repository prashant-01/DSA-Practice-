 #include<bits/stdc++.h>
 using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int , int>>v;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            v.push_back(make_pair(nums[i] , i));
        }
        sort(v.begin() , v.end());
        int l=0,h=v.size();
        while(l<h){
            long sum=v[l].first + v[h].first;
            if(sum > target)h--;
            else if(sum < target)l++;
            else {
                ans.push_back(v[l].second);
                ans.push_back(v[h].second);
                break;
            }
        }
        return ans;
    }
int main(){
    vector<int>nums{3 , 30 , 34 , 9 , 5 , 10 , 100};
    int target=110;
    vector<int>ans=twoSum(nums , target);
    cout << ans[0] << " , " << ans[1];
}