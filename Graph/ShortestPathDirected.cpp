#include<bits/stdc++.h>
using namespace std;

// ! expecting no cycle bcoz it is mentioned that graph is DAG
void dfs(vector<pair<int , int>>adj[] , vector<int>&vis , stack<int>&s , int node){
    vis[node]=1;
    for(auto child : adj[node]){
        if(!vis[child.first]){
            dfs(adj , vis , s , child.first);
        }
    }
    s.push(node);
    return;
}

int main(){
    int n , m , x , y , d , src=0;
    stack<int>s;
    vector<pair<int , int>>adj[n];
    vector<int>vis(n , 0) , dis(n , INT_MAX);
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> x >> y >> d;
        adj[x].push_back({y , d});
    }
    // ! Get topo order
    dfs(adj , vis , s , src);
    
    // ! visit adj nodes of each node in topo order
    dis[src]=0;
    while(!s.empty()){
        int node = s.top();
        s.pop();
        for(auto child : adj[node]){
            dis[child.first] = min( dis[child.first] , dis[node]+child.second );
        }
    }
    for(int i=0 ; i<n ; i++){
        if(dis[i] == INT_MAX)dis[i]=-1;
    }
    for(int i=0 ; i<n ; i++)cout << dis[i] << " ";
}