class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        vector<vector<int>> ans(r, vector<int>(c, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if (mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int colp[] = {0, 1, 0, -1};
        int rowp[] = {-1, 0, 1, 0};
        while(!q.empty()){
            int rown = q.front().first.first;
            int coln = q.front().first.second;
            int dist = q.front().second; 
            q.pop();
            ans[rown][coln] = dist;
            for(int k=0; k<4; k++){
                int newr = rown + rowp[k];
                int newc = coln + colp[k];
                if (newr>=0 && newr<r && newc>=0 && newc<c
                    && vis[newr][newc] == 0){
                        q.push({{newr, newc}, dist+1});
                        vis[newr][newc] = 1;
                    }
            }

        }
        return ans;
    }
};