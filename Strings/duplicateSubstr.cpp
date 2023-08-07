#include<bits/stdc++.h>
using namespace std;

string removeSubStr(string s , string part){
    int pos=s.find(part);
    while(pos != string::npos){
        s.erase(pos , part.length());
        pos=s.find(part);
    }
    return s;
}
int main(){
    string s,part,ans;cin >> s >> part;
    ans=removeSubStr(s,part);
    cout << ans;
}