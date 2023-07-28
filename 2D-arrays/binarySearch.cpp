#include<bits/stdc++.h>
using namespace std;
//Formula to convert (i,j) ---> linear index : cols*i + j [cols is the total no of cols in that matrix]
//Eg matrix 5x5 & linear index of (1,3) ---> 5*1+3 = 8th index 

//Formula to convert Linear index to (i,j) -- > i=mid/cols ; j=mid%cols;

int binarySearch(vector<vector<int>>v , int target){
    int n=v.size();
    int m=v[0].size();
    int l=0,r=n*m-1,mid,i,j;

    while(l<=r){
        mid=l+(r-l)/2;
        i=mid/m;
        j=mid%m;
        if(v[i][j] == target)return mid;
        else if(v[i][j] > target){
            r=mid-1;
        }
        else l=mid+1;
    }
    return -1;
}
int main(){
    vector<vector<int>>v(5,vector<int>(5));
    int target;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cin >> v[i][j];
        }
    }
    cin >> target;
    int ans = binarySearch(v,target);
    if(ans == -1)cout << "Not Found" ;
    else{
        cout << ans/v[0].size() << " , " <<  ans%v[0].size();
    }
}

