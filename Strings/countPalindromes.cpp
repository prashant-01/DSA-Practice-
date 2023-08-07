 #include<bits/stdc++.h>
 using namespace std;

 
  int expandAroundIndex(string s , int i , int j){
        int count=0,n=s.length();;
        while(i >= 0 && j <=n-1 && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        //counting odd substrings
        int i,j,count=0, n=s.length();
        for(int k=0;k<n;k++){
            i=k,j=k;
            count+=expandAroundIndex(s,i,j);
        }
        //counting even substring
        for(int k=0;k<n;k++){
            i=k,j=k+1;
            count+=expandAroundIndex(s,i,j);
        }
        return count;
    }

    int main(){
        string s;cin >> s;
        cout << countSubstrings(s);
    }