#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s , int i , int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++;j--;
        }
        else return false;
    }
    return true;
}

bool validPalindrome(string s){
    int i=0 , j=s.length()-1;
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            if(checkPalindrome(s , i+1 , j) || checkPalindrome(s , i , j-1))return true;
            else return false;
        }
    return true;
    }
}
int main(){
string s;cin >> s;
bool b = validPalindrome(s);
cout << b;
}