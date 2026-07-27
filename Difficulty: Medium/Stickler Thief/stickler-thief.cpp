class Solution {
  private:
    int dfs(vector<int>& arr, vector<int>&dp, int i){
        if (i<0){
            return 0;
        }
        if (dp[i]!=-1) return dp[i];
        int left = dfs(arr, dp, i-2) + arr[i];
        int right = dfs(arr, dp,  i-1);
        return dp[i] = max(left, right);
    }
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        return dfs(arr, dp, n-1);
        
    }
};