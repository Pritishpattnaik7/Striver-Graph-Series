#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    for (auto x : adj[node]){
        if (vis[x] == 0){
            dfs(x, adj, vis);
        }
    }
}

int numProvinces(vector<vector<int>> mat, int n){
    //1 based -> n+1 size
    //first we need to convert the adjacency matrix to adj list
    vector<int> adj[n+1];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (mat[i][j] == 1){
                adj[i+1].push_back(j+1);
            }
        }
    }

    int ans = 0;
    vector<int> vis(n+1, 0);
    for (int i=1 ; i<=n ; i++){
        if (vis[i] == 0){
            ans++;
            dfs(i, adj, vis);
        }
    }

    return ans;
}


/*
Time complexity -> O(n) / O(n) + O(v + 2e)
Space Complexity -> O(n)
*/

int main(){
}