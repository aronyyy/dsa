class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis){
        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];
                if(newr>=0 && newr<n &&
                    newc>=0 && newc<m &&
                    grid[newr][newc]==1 &&
                    !vis[newr][newc]){
                        q.push({newr, newc});
                        vis[newr][newc] = 1;
                    }
            }

        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));

        // Left boundary
        for(int i=0;i<r;i++) {
            if(grid[i][0]==1 && !vis[i][0]) {
                bfs(i,0,grid,vis);
            }
        }

        // Top boundary
        for(int j=0;j<c;j++) {
            if(grid[0][j]==1 && !vis[0][j]) {
                bfs(0,j,grid,vis);
            }
        }

        // Right boundary
        for(int i=0;i<r;i++) {
            if(grid[i][c-1]==1 && !vis[i][c-1]) {
                bfs(i,c-1,grid,vis);
            }
        }

        // Bottom boundary
        for(int j=0;j<c;j++) {
            if(grid[r-1][j]==1 && !vis[r-1][j]) {
                bfs(r-1,j,grid,vis);
            }
        }

        int cnt=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {

                if(grid[i][j]==1 && !vis[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};