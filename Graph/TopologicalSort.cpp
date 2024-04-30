#include<bits/stdc++.h>
using namespace std;

// ! Topological Sort is only valid in case of DAG (Directed Acyclic Graph)



void dfs(vector<int> adj[] , vector<int>&vis , stack<int>&s , int node){
    // TODO : Apply cycle detection code (pathVis wala) also to check whether Topo can be calculated or not
    vis[node]=1;
    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(adj , vis , s , child);
        }
    }
    s.push(node);
    return;
}

// * Kahn's Algorithm
void bfs(vector<int> adj[] , vector<int>&inDegree , queue<int>&q , vector<int>&ans){
    // ! Here cycle detection code is not required because when inDegree of all nodes is
    // ! != 0 then queue -> empty  hence no BFS
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto child : adj[node]){
            inDegree[child]--;
            if(inDegree[child] == 0)q.push(child);
        }
    }
    return;
}
int main(){
    int n , m , x , y;
    cin >> n >> m;
    vector<int> adj[n+1] , vis(n , 0) , inDegree(n , 0) , ans;
    stack<int>s;
    queue<int>q;
    for(int i=0 ; i<m ; i++){
        cin >> x >> y;
        inDegree[y]++;
        adj[x].push_back(y);;
    }
    for(int i=0 ; i<n ; i++){
        if(inDegree[i] == 0)q.push(i);
    }
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
            dfs(adj , vis , s , i);
            bfs(adj , inDegree , q , ans);
        }
    }
    cout << "Using DFS" << " ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << "Using BFS" << " ";;
    for(int i=0 ; i<ans.size() ; i++)
        cout << ans[i] << " ";
}