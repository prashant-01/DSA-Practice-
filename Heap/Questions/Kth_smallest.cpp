#include <bits/stdc++.h>
using namespace std;
// for kth smallest create max heap of size k
// for kth largest create max heap of size (n-k)
void heapInsertion(vector<int>&heap , int val){
    heap.push_back(val);
    int index = heap.size()-1;
    while(index > 1){
        int parent = index/2;
        if(heap[parent] < heap[index]){
            swap(heap[parent] , heap[index]);
            index = parent;
        }
        else return;
    }
}

void heapDeletion(vector<int>&heap){
    swap(heap[1] , heap[heap.size()-1]);
    // decreasing size by 1;
    heap.pop_back();
    int size = heap.size();

    int index = 1;
    // putting new replaced node at its correct position
    while(index < size){
        int leftChild = 2*index;
        int rightChild = 2*index + 1;
        if(leftChild < size && heap[index] < heap[leftChild]){
            swap(heap[index] , heap[leftChild]);
            index = leftChild;
        }
        if(rightChild < size && heap[index] < heap[rightChild]){
            swap(heap[index] , heap[rightChild]);
            index = rightChild;
        }
        else return;
    }
}
int main(){
    vector<int>v = { 18 , 61 , 42 , 75 , 21 , 25 , 27 , 3 , 10 , 15 };
    vector<int>heap;
    heap.push_back(-1);
    int k=1;
    for(int i=0 ; i<k; i++)heapInsertion(heap , v[i]);
    for(int i=k ; i<v.size() ; i++){
        if(heap[1] > v[i]){
            heapDeletion(heap);
            heapInsertion(heap , v[i]);
        }
    }
    // for(int i=0 ; i<heap.size() ; i++)cout << heap[i] << " "; 
    cout << "kth smallest " << heap[1];
}