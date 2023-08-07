#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int>v , int pages){
    int currPages=0,students=1;
    for(int i=0;i<v.size();i++){
        if(currPages+v[i] > pages){
            students++;
            currPages=v[i];
        }
        else currPages+=v[i];
    }
    return students;
}
int findPages(vector<int>v,int m){
    int sum=0,mid,n=v.size(),mx=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        if(v[i] > mx)mx=v[i];
    }

    int l=mx,h=sum,ans=-1;
    //binarySearch 
    while(l<=h){
        mid=l+(h-l)/2;
        if(countStudents(v,mid) > m)l=mid+1;
        else {
            h=mid-1;
        }
    }
    return mid;
}

int main(){
    int n,m;cin >> n;cin>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << findPages(v,m);
}