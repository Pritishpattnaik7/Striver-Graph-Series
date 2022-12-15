#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<int> adj[], int n){
    for (int i=1 ; i<=n ; i++){
        cout << i << "->";
        for (auto x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
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
    printGraph(adj, n);


    //for storing weighted graph
    vector<pair<int, int>> adjWei[n+1];
    for (int i=0 ; i<m ; i++){
        int u1, v1, wt;
        cin >> u1 >> v1 >> wt;
        adjWei[u1].push_back({v1, wt});
        adjWei[v1].push_back({u1, wt});
    }
}