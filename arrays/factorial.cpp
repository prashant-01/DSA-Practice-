#include<bits/stdc++.h>
using namespace std;

vector<int> calcFactorial(int n){
    vector<int>ans;
    ans.push_back(1);
    int carry=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<ans.size();j++){
            int x=ans[j]*i+carry;
            ans[j]=x%10;
            carry=x/10;
        }
        if(carry!=0)ans.push_back(carry);
        carry=0;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int>ans=calcFactorial(n);
    //for(auto i:ans)cout << i << " ";
    for(auto i=ans.rbegin() ; i!=ans.rend() ; i++)cout << *i << " ";
}