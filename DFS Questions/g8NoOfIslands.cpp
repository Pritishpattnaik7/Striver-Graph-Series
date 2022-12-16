//can be done in both bfs and dfs
//all 8 directions
#include<bits/stdc++.h>
using namespace std;

//dfs is preffered
void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vis[i][j] = 1;

    //now traverse for it's adjacent neighbours
    for (int deli=-1 ; deli<=1 ; deli++){
        for (int delj=-1 ; delj<=1 ; delj++){
            int ni = i + deli;
            int nj = j + delj;
            if (ni >= 0 and ni < n and nj >= 0 and nj < m and
            grid[ni][nj] == '1' and vis[ni][nj] == 0){
                dfs(ni, nj, vis, grid);
            }
        }
    }
}

//bfs
void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        //now traverse for it's adjacent neighbours
        for (int deli=-1 ; deli<=1 ; deli++){
            for (int delj=-1 ; delj<=1 ; delj++){
                int ni = i + deli;
                int nj = j + delj;
                if (ni >= 0 and ni < n and nj >= 0 and nj < m and
                grid[ni][nj] == '1' and vis[ni][nj] == 0){
                    vis[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }
    }
}


int numIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int ans = 0;

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (grid[i][j] == '1' and vis[i][j] == 0){
                ans++;
                dfs(i, j, vis, grid);
            }
        }
    }

    return ans;
}

int main(){
}