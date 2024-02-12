 #include<bits/stdc++.h>
 using namespace std;

 int partition(vector<int>&v , int s , int e){
    int i=s , j=e , pivot = v[s];
    while(i<=j){
        while(v[i] <= pivot)i++;
        while(v[j] > pivot)j--;
        if(i <= j){
            swap(v[i] , v[j]);
        }
    }
    swap(v[s] , v[j]);
    return j;
 }

 void quickSort(vector<int>&v , int s , int e){
    if(s >= e)return;
    int pivot = partition(v , s , e);
    quickSort(v , s , pivot-1);
    quickSort(v , pivot+1 , e);
 }

 int main(){
    vector<int>v={3,1,4,2,8,0};
    quickSort(v,0,v.size()-1);
    for(int i=0 ; i < v.size() ; i++)cout << v[i] << " ";
 }