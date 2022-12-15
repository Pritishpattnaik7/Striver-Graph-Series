#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[]){
    vector<int> ans;
    vector<int> vis(n, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto x : adj[node]){
            if (vis[x] == 0){
                vis[x] = 1;
                q.push(x);
            }
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

    vector<int> ans = bfsOfGraph(n, adj);
    for (auto x : ans){
        cout << x << " ";
    }
}