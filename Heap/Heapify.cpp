#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v , int i){
    int largest = i;
    int leftNode = 2*i;
    int rightNode = 2*i + 1;

    if(leftNode < v.size() && v[largest] < v[leftNode])largest=leftNode;
    if(rightNode < v.size() && v[largest] < v[rightNode])largest=rightNode;

    if(largest != i){
        swap(v[i] , v[largest]);
        heapify(v , largest);
    }
    else return;
}
int main(){
    vector<int>v = { 19 , 24 , 21 , 31 , 9 , 18 , 2 };
    int size = v.size();
    for(int i = size/2 ; i >= 0 ; i--) heapify(v , i);
    for(int i=0 ; i<size ; i++)cout << v[i] << " ";
}