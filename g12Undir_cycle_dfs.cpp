#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (vis[x] == 0){
            if (dfs(x, node, vis, adj) == true){
                return true;
            }
        }
        else if (vis[x] == 1 and x != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    for (int i=0 ; i<n ; i++){
        if (vis[i] == 0){
            if (dfs(i, -1, vis, adj) == true) return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    //adjacency list representation
    vector<int> adj[n+1];
    for (int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


}