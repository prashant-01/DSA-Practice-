#include<bits/stdc++.h>
using namespace std;
vector<int>commonElementsSearch(vector<int>v , vector<int>v1 , vector<int>v2){
    vector<int>common;
    int i=0,j=0,k=0;
    while(i<v.size() && j<v1.size() && k<v2.size()){
        if(v[i]==v1[j] && v1[j]==v2[k]){
            common.push_back(v[i]);
            i++;j++;k++;
        }
        else if(v[i]<v1[j])i++;
        else if(v1[j]<v2[k])j++;
        else k++;
    }
    return common;
}
int main(){
    vector<int>v{2,4,6,8};
    vector<int>v1{3,4,5,6,7,8};
    vector<int>v2{5,6,7,8,9};
    vector<int>common=commonElementsSearch(v,v1,v2);
    for(int i=0;i<common.size();i++)cout<<common[i]<<" ";
}