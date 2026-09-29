class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if ((m + n - 1) % 2 != 0)
            return false;
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false))
        );
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
        return dp[m - 1][n - 1][0];
    }
};