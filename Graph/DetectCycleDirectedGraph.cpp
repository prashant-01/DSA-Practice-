#include<bits/stdc++.h>
using namespace std;
  
bool detectCycleDFS(vector<int> adj[] , vector<int>&vis , vector<int>&path , int node){
    vis[node]=1;
    path[node]=1;
    for(auto child : adj[node]){
        if(!vis[child]){
            bool res = detectCycleDFS(adj , vis , path , child);
            if(res)return true;
        }
        else if(path[child]){
            return true;
        }
    }
    path[node]=0;
    return false;
}
int main(){
    int n , m , x , y;
    bool ans=false;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int>vis(n+1 , 0) , path(n+1 , 0);
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);;
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            if(detectCycleDFS(adj , vis , path , i)){
                ans=true;
            }
        }
    }
    cout << ans;
}