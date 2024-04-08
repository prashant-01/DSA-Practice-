#include <bits/stdc++.h>
using namespace std;

void heapInsertion(vector<int>&v){
    int index = v.size()-1;
    while(index > 1){
        int parent = index/2;
        if(v[parent] < v[index]){
            swap(v[parent] , v[index]);
            index = parent;
        }
        else return;
    }
}

int main(){
    vector<int>v;
    v.push_back(-1);
    int n;
    while(1){
        cin >> n;
        if(n == -1)break;
        v.push_back(n);
        heapInsertion(v);
    }
    return;
}