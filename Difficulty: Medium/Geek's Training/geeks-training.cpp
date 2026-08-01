class Solution {
public:
    int dfs(int day, int last, vector<vector<int>>& mat, vector<vector<int>>& dp) {

        // Base case
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last)
                    maxi = max(maxi, mat[0][task]);
            }
            return maxi;
        }
        if (dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;

        // Choose any task except 'last'
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int points = mat[day][task] + dfs(day - 1, task, mat, dp);
                maxi = max(maxi, points);
            }
        }

        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        return dfs(n - 1, 3, mat, dp);   // 3 means "no previous task"
    }
};