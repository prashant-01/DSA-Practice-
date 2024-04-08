#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v , int i , int size){
    int largest = i;
    int leftNode = 2*i;
    int rightNode = 2*i + 1;

    if(leftNode < size && v[largest] < v[leftNode])largest = leftNode;
    if(rightNode < size && v[largest] < v[rightNode])largest = rightNode;

    if(largest != i){
        swap(v[i] , v[largest]);
        heapify(v , largest , size);
    }
    else return;
}
void heapSort(vector<int>&v){
    int size = v.size();
    while(size > 1){
        swap(v[1] , v[size-1]);
        size--;
        heapify(v , 1 , size);
    }
}
int main(){
    vector<int>v = { -1 , 18 , 61 , 42 , 75 , 21 , 25 , 27 , 3 , 10 , 15 };
    for(int i = v.size()/2 ; i > 0 ; i--) heapify(v , i , v.size());
    heapSort(v);
    for(int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
}