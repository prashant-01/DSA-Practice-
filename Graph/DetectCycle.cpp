#include<bits/stdc++.h>
using namespace std;

bool detectCycleBFS(vector<int> adj[] , vector<int>&vis , int src){
    queue<pair<int , int>>q;
    q.push({src , -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        vis[node]=1;
        for(auto child : adj[node]){
            if(!vis[child]){
                q.push({child , node});
            }
            else if(child != parent){
                return true;
            }
        }
    }
    return false;
}
    
bool detectCycleDFS(vector<int> adj[] , vector<int>&vis , int node , int parent){
    vis[node]=1;
    for(auto child : adj[node]){
        if(!vis[child]){
            bool res = detectCycleDFS(adj , vis , child , node);
            if(res)return true;
        }
        else if(child != parent){
            return true;
        }
    }
    return false;
}
int main(){
    int n , m , x , y;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int>vis(n+1 , 0);
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        // adj[y].push_back(x);
    }
    cout << detectCycleDFS(adj , vis , 1 , -1);
}