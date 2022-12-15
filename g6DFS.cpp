//DFS
//TC -> O(V+E)
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);
    for (auto x : adj[node]){
        if (vis[x] == 0){
            dfs(x, adj, vis, ans);
        }
    }
}
    
vector<int> dfsOfGraph(int n, vector<int> adj[]) {
    // Code here
    vector<int> vis(n, 0);
    vector<int> ans;
    for (int i=0 ; i<n ; i++){
        if (vis[i] == 0){
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
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

    vector<int> ans = dfsOfGraph(n, adj);
    for (auto x : ans){
        cout << x << " ";
    }
}