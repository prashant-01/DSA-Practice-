#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string s){
    string ans;
    ans.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        if(ans.length() >= 1 && ans[ans.size()-1] == s[i])ans.pop_back();
        else ans.push_back(s[i]);
    }
    return ans;
}
int main(){
    string s;cin >> s;
    cout << removeDuplicate(s);
    
}