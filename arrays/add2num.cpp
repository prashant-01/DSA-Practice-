#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v1{9,0,0,3,5};
    vector<int>v2{7,5,6,2,7};
    vector<int>sum;
    int carry=0;
    int i=v1.size()-1 , j=v2.size()-1 , currSum;
    while(i>=0 || j>=0){
        if(i<0)currSum=v2[j]+carry;
        else if(j<0) currSum=v1[i]+carry;
        else currSum=v1[i]+v2[j]+carry;

        if(currSum>=10){
            sum.push_back(currSum%10);
            carry=1;
        }
        else{
            sum.push_back(currSum);
            carry=0;
        }
        i--;j--;
    }

    if(carry==1)sum.push_back(carry);

    for(int x=sum.size()-1;x>=0;x--){
        if(sum[x]==0)sum.pop_back();
        else if (sum[x]!=0) break;
    }
    for(int x=sum.size()-1;x>=0;x--)cout<<sum[x]<<" ";
}