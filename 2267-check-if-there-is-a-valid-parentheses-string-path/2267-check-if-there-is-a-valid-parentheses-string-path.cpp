class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length.
        if ((m + n - 1) % 2 != 0)
            return false;

        // dp[i][j][balance] = whether we can reach (i,j)
        // with the given parentheses balance.
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );

        // Starting cell.
        if (grid[0][0] == ')')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(' ? 1 : -1);

                // Come from above.
                if (i > 0) {
                    for (int balance = 0; balance <= m + n - 1; ++balance) {
                        if (!dp[i - 1][j][balance])
                            continue;

                        int newBalance = balance + change;

                        if (newBalance >= 0)
                            dp[i][j][newBalance] = true;
                    }
                }

                // Come from the left.
                if (j > 0) {
                    for (int balance = 0; balance <= m + n - 1; ++balance) {
                        if (!dp[i][j - 1][balance])
                            continue;

                        int newBalance = balance + change;

                        if (newBalance >= 0)
                            dp[i][j][newBalance] = true;
                    }
                }
            }
        }

        // Valid iff the final balance is exactly 0.
        return dp[m - 1][n - 1][0];
    }
};