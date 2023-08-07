#include<bits/stdc++.h>
using namespace std;
void sortArray(vector<int>num){
    int l=0,r=num.size() , mid=0;
    while(mid < r){
        if(num[mid]==0){
            swap(num[l] , num[mid]);
            l++;
            mid++;
        }
        else if(num[mid]==1){
            mid++;
        }
        else{
            swap(num[mid] , num[r]);
            r--;
        }
    }
    for(int i=0;i<num.size();i++)cout<<num[i] << " ";
}
int main(){
    vector<int>v(7);
    for(int i=0;i<v.size();i++)cin>>v[i];
    sortArray(v);
}