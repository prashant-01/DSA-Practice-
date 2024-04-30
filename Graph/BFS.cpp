#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[] , vector<int> &vis , int i){
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " " ;
        for( auto c : adj[node] ){
            if(!vis[c]){
                vis[c]=1;
                q.push(c);
            }
        }
    }
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
            bfs(adj , vis , i);
        } 
    }
    cout << endl << "Number of components " << components;
}