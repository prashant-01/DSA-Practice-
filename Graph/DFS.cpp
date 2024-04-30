#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[] , vector<int> &vis , int node){
    vis[node]=1;
    cout << node << " ";
    for( auto c : adj[node] ){
        if(!vis[c]){
            vis[c]=1;
            dfs(adj , vis , c);
        }
    }
    return;
}
int main(){
    int n , m , x , y , components=0;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int>vis(n+1 , 0);
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            components++;
            dfs(adj , vis , i);
        } 
    }
    cout << endl << "Number of components " << components;
}