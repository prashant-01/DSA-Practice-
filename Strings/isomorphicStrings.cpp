#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
        int n=s.size();
        vector<int>hash(256 , 0);
        vector<bool>isMapped(256 ,0);
        for(int i=0;i<n;i++){
            if(hash[s[i]] == 0 && isMapped[t[i]] == 0){
                hash[s[i]]=t[i];
                isMapped[t[i]]=true;
            }
        }

        for(int i=0;i<n;i++){
            if(hash[s[i]] != t[i])return false;
        }
        return true;
}

int main(){
    string s,t;cin>>s>>t;
    cout << isIsomorphic(s,t);
}