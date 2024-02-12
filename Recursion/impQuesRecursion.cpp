 #include<bits/stdc++.h>
 using namespace std;

 int minElements(vector<int>v , int n){
   if(n==0)return 0;
   if(n < 0)return INT_MAX;
   int mn=INT_MAX;
   for(int i=0;i<v.size();i++){
      int ans=minElements(v , n-v[i]);
      if(ans != INT_MAX)mn=min(ans+1,mn);
   }
   return mn;
 }

 int maxSegments(vector<int>v , int n){
   if(n==0)return 0;
   if(n < 0)return INT_MIN;
   int mx=INT_MIN;
   for(int i=0;i<v.size();i++){
      int ans=maxSegments(v , n-v[i]);
      if(ans != INT_MIN)mx=max(ans+1 , mx);
   }
   return mx;
 }

int maxSubsequenceSum(vector<int>v , int i){
   if(i >= v.size()){
      return 0;
   }
   int sum1 = maxSubsequenceSum(v,i+1);
   int sum2 = v[i] + maxSubsequenceSum(v,i+2);
   return max(sum1 , sum2);
}

 int main(){
    vector<int>v={2,9,3,4};
    //cout << minElements(v , 2);
    //cout << maxSegments(v , 7);
    cout << maxSubsequenceSum(v,0); // House Robber Problem Leetcode-198 
 }