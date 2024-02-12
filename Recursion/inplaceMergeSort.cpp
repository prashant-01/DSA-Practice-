#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v , int start , int end){
    int totalLen = end-start+1;
    int gap=(totalLen/2) + totalLen%2;
    while(gap > 0){
        int i=start , j=start+gap;
        while(j <= end){
            if(v[i] > v[j]){
                swap(v[i] , v[j]);
            }
            i++; j++;
        }
        gap=gap <= 1 ? 0 : (gap/2) + gap%2;
    }
}
void mergeSort(vector<int>&v , int start , int end){
    if(start >= end)return;

    int mid=start+(end-start)/2;
    mergeSort(v , start , mid);
    mergeSort(v , mid+1 , end);
    merge(v , start , end);
}
int main(){
    vector<int>v={8,6,5,3,7,4,1,2};
    mergeSort(v , 0 , v.size()-1);
    for(auto it:v)cout << it << " ";
}