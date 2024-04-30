#include <bits/stdc++.h>
using namespace std;

void heapInsertion(vector<int>&v){
    int index = v.size()-1;
    while(index > 0){
        int parent = index/2;
        if(v[parent] < v[index]){
            swap(v[parent] , v[index]);
            index = parent;
        }
        else return;
    }
}

// deletion in heap is root node deleteion
void heapDeletion( vector<int>&v ){
    // put last node at root position
    v[0]=v[v.size()-1];
    v.pop_back();
    int size = v.size();

    // now putting this new root at this correct pos
    int index = 0;
    while(index < size){
        int leftChildIndex = 2*index + 1 ;
        int rightChildIndex = 2*index + 2;
        if(leftChildIndex <= size && v[index] < v[leftChildIndex]){
            swap(v[index] , v[leftChildIndex]);
            index = leftChildIndex ;
        }
        if(rightChildIndex <= size && v[index] < v[rightChildIndex]){
            swap(v[index] , v[rightChildIndex]);
            index = rightChildIndex ;
        }
        else return;
    }
}
int main(){
    vector<int>v;
    int n;
    while(1){
        cin >> n;
        if(n == -1)break;
        v.push_back(n);
        heapInsertion(v);
    }
    cout << "before deletion";
    for(int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
    heapDeletion(v);
    cout << "after deletion";
    for(int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
}