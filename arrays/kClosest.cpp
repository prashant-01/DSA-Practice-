#include<bits/stdc++.h>
using namespace std;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int l=0,h=arr.size()-1;
            while(h-l>=k){
                if(x-arr[l] > arr[h]-x)l++;
                else h--;
            }
            // vector<int>ans;
            // for(int i=l;i<=h;i++)ans.push_back(arr[i]);
            // return ans;
            //Can also return without using extra space
            return vector<int> (arr.begin()+l , arr.begin()+h+1);
    }
int main(){
    vector<int>v(8);
    for(int i=0;i<8;i++)cin >> v[i];
    vector<int>ans;
    int k,x;
    cin >>k;
    cin >>x;
    ans=findClosestElements(v,k,x);
    for(int i=0;i<k;i++)cout <<ans[i]<<" ";
} 