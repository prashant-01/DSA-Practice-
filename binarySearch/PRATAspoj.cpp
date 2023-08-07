#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>cooksRank , int nP , int mid){
    int currPrata=0;
    for(int i=0;i<cooksRank.size();i++){
        int j=1 , timeTaken=0;
        int rank = cooksRank[i];
        while(true){
            if(timeTaken + j*rank <= mid){
                currPrata++;
                timeTaken+=j*rank;
                j++;
            }
            else{
                break ; //next wale cook p shift kro 
            }
        }
        if(currPrata>=nP)return true;
    }
    return false;
}
int minTimeToCook(vector<int>cooksRank , int nP){
    int l=0,mid,ans=-1;
    int h=*max_element(cooksRank.begin() , cooksRank.end()) * (nP*(nP+1)/2);

    while(l<=h){
        mid=l+(h-l)/2;
        if(isPossible(cooksRank , nP , mid)){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    int t,c,nP;
    cin >> t;
    while(t--){
        cin >> nP;
        cin >> c;
        vector<int>cooksRank(c);
        for(int i=0;i<c;i++)cin>>cooksRank[i];
        cout << minTimeToCook(cooksRank , nP) << "\n";
    }
}