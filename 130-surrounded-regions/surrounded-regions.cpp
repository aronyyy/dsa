class Solution {
public:
    void dfs(int r,
         int c,
         vector<vector<char>>& board,
         vector<vector<int>>& vis){

    int n = board.size();
    int m = board[0].size();

    vis[r][c] = 1;

    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    for(int i=0;i<4;i++){

        int newr = r + drow[i];
        int newc = c + dcol[i];

        if(newr>=0 && newr<n &&
           newc>=0 && newc<m &&
           board[newr][newc]=='O' &&
           !vis[newr][newc]){

            dfs(newr,newc,board,vis);
        }
    }
}
    void solve(vector<vector<char>>& board) {

    int r = board.size();
    int c = board[0].size();

    vector<vector<int>> vis(r, vector<int>(c,0));

    // Left boundary
    for(int i=0;i<r;i++) {
        if(board[i][0]=='O' && !vis[i][0]) {
            dfs(i,0,board,vis);
        }
    }

    // Top boundary
    for(int j=0;j<c;j++) {
        if(board[0][j]=='O' && !vis[0][j]) {
            dfs(0,j,board,vis);
        }
    }

    // Right boundary
    for(int i=0;i<r;i++) {
        if(board[i][c-1]=='O' && !vis[i][c-1]) {
            dfs(i,c-1,board,vis);
        }
    }

    // Bottom boundary
    for(int j=0;j<c;j++) {
        if(board[r-1][j]=='O' && !vis[r-1][j]) {
            dfs(r-1,j,board,vis);
        }
    }

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {

            if(board[i][j]=='O' && !vis[i][j]) {
                board[i][j]='X';
            }
        }
    }
}
};