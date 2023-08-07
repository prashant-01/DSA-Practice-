#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        int n1=s.length() , n2=t.length();
        if(n1!=n2)return false;
        else{
            vector<int>s1(26 , 0),t1(26 , 0);
            for(int i=0;i<n1;i++){
                s1[s[i]-'a']++;
                t1[t[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(s1[i] != t1[i]){
                    return false;
                }
            }
            return true;
        }
}

int main(){
    string s,t;cin >> s>>t;
    cout << isAnagram(s,t);
}