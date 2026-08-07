class Solution {
public:
    void solve(int open, int close, int pairs,
               string curr, vector<string>& ans) {

        if (curr.size() == 2 * pairs) {
            ans.push_back(curr);
            return;
        }

        // Add an opening bracket
        if (open < pairs) {
            solve(open + 1, close, pairs, curr + "(", ans);
        }

        // Add a closing bracket
        if (close < open) {
            solve(open, close + 1, pairs, curr + ")", ans);
        }
    }

    vector<string> generateParentheses(int n) {

        vector<string> ans;
        int pairs = n / 2;

        solve(0, 0, pairs, "", ans);

        return ans;
    }
};