#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>v , vector<vector<bool>>&visited , int i , int j , int rows , int cols){
    if(i > rows-1 || j > cols-1 || i < 0 || j < 0 || v[i][j] == 0 || visited[i][j] == true)return false;
    return true;
}

void findDestination(vector<vector<int>>v , vector<vector<bool>>&visited , int i , int j , int rows , int cols , 
string &output , vector<string>&paths , int& mn , int &mx , int dist){
    /***********Base-Case***********/
    if(i == rows-1 && j == cols-1){
        paths.push_back(output);
        mn=min(mn , dist);
        mx=max(mx,dist);
        return;
    }
    /*******************************/

    if(isSafe(v , visited , i+1 , j , rows , cols)){
        visited[i+1][j]=true;
        output.push_back('D');
        findDestination(v,visited , i+1 , j , rows , cols , output , paths , mn , mx , dist+1);
        //backtrack
        output.pop_back();
        visited[i+1][j]=false;
    }
    if(isSafe(v , visited , i , j+1 , rows , cols)){
        visited[i][j+1]=true;
        output.push_back('R');
        findDestination(v,visited , i , j+1 , rows , cols , output , paths , mn , mx , dist+1) ;
        //backtrack
        output.pop_back();
        visited[i][j+1]=false;
    }
    if(isSafe(v , visited , i-1 , j , rows , cols)){
        visited[i-1][j]=true;
        output.push_back('U');
        findDestination(v,visited , i-1 , j , rows , cols , output , paths , mn , mx , dist+1) ;
        //backtrack
        output.pop_back();
        visited[i-1][j]=false;
    }
    if(isSafe(v , visited , i , j-1 , rows , cols)){
        visited[i][j-1]=true;
        output.push_back('L');
        findDestination(v,visited , i , j-1 , rows , cols , output , paths , mn , mx , dist+1 );
        //backtrack
        output.pop_back();
        visited[i][j-1]=false;
    }
}
int main(){
    int rows=4 , cols=4;
    string output="";
    vector<string>paths;
    vector<vector<int>>v = {{1,1,1,0} , 
                            {1,1,1,1} ,
                            {0,1,0,1} ,
                            {1,1,1,1}};
    vector<vector<bool>>visited(4 , vector<bool>(4 , false));
    visited[0][0]=true;
    int mn=INT_MAX , mx=INT_MIN;
    findDestination(v , visited , 0  , 0 , rows , cols , output , paths , mn , mx , 0);
    for(auto it:paths)cout << it << endl;
    cout << "Minimum Path -> " << mn << endl;
    cout << "Maximum Path -> " << mx << endl;
}