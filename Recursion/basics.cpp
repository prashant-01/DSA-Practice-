 #include<bits/stdc++.h>
 using namespace std;

void printVec(int v[] , int n){
    if(n<0)return;
    cout << *(v+n) << " ";
    return printVec(v , n-1);
}

string reverseStr(string &s , int i){
    if(i >= s.size()/2){
        return s;
    }
    swap(s[i] , s[s.size()-1-i]);
    reverseStr(s,i+1);
}

string addStr(string s1 , string s2 , int n1 , int n2 , int carry){
    string ans="";
    if(n1 < 0 && n2 < 0){
        if(carry){
            ans.push_back(carry + '0');
        }
        return ans;
    }
    int x = ((n1>=0) ? s1[n1] : '0')-'0';
    int y = ((n2>=0) ? s2[n2] : '0')-'0';
    int z=(x+y+carry);
    carry=z/10;

    ans.push_back(z%10 + '0');
    ans += addStr(s1 , s2 , n1-1 , n2-1 , carry);
}

void removeAllOccurences(string &s , string part){
    int pos=s.find(part);   
    if(pos != string::npos){
        string left_part=s.substr(0 , pos);
        string right_part=s.substr(pos+part.size() , s.size());
        s=left_part+right_part;
        removeAllOccurences(s,part);
    }
    else return;
}

void printSA(vector<int>nums , int start , int end){
    if(end == nums.size())return;
    for(int i=start;i<=end;i++){
        cout << nums[i];
    }
    cout << endl;
    printSA(nums , start , end+1);
}

void printSubArrays(vector<int>nums){
    for(int start=0;start<nums.size();start++){
        int end=start;
        printSA(nums , start , end);
    }
}
int main(){
    //vector<int>v = {1,2,3,4,5,6};
    // int v[]={1,2,3,4,5,6};
    // printVec(v , 5);

/*****************************************************/

    // string s="Prashant";
    // reverseStr(s,0);
    // cout << s;

/*****************************************************/

    // string s1="123";
    // string s2="9893";
    // int carry=0;
    // string ans = addStr(s1 , s2 , s1.size()-1 , s2.size()-1 , carry);
    // reverse(ans.begin() , ans.end());
    // cout << ans;

/*****************************************************/
    // string s="daabcbaabcbc";
    // string part="ds";
    // removeAllOccurences(s,part);
    // cout << s;

/*****************************************************/
vector<int>nums={1,2,3,4,5};
printSubArrays(nums);
}

