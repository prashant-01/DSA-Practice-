#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v(10);
    for(int i=0;i<v.size();i++)cin>>v[i];
    unordered_map<int , int>mapCount;
    for(int i=0;i<v.size();i++)mapCount[v[i]]++;
    for(int i=0;i<v.size();i++){
        if(mapCount[v[i]]>1){
            cout<<v[i];
            return 0;
        }
    }
    return-1;
}
