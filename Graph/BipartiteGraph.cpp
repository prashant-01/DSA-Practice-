#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<int> adj[] , vector<int> &color , int src){
    queue<int>q;
    q.push(src);
    color[src]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for( auto c : adj[node] ){
            if(color[c] == -1){
                color[c]=!color[node];
                q.push(c);
            }
            else if(color[c] == color[node])
                return false;
        }
    }
    return true;
}

bool dfs(vector<int> adj[] , vector<int> &color , int node , int c){
    if(color[node] == -1)
        color[node]=!c;
    for(auto child : adj[node]){
        if(color[child] == -1){
            color[child] = !color[node];
            dfs(adj , color , child , node);
        }
        else if(color[child] == color[node])
            return false;
    }
    return  true;
}
int main(){
    int n , m , x , y;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int>color(n+1 , -1);
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // cout << bfs(adj , color , 1);
    cout << dfs(adj , color , 1 , 0);
}
