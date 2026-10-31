
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(2, 0))
        );
        long long right, down;
        dp[0][0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                right = dp[i][j][0];
                down = dp[i][j][1];

                if (grid[i][j] == 1) {
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + right) % MOD;
                    }
                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + down) % MOD;
                    }
                }
                else {
                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + right + down) % MOD;
                    }
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + right + down) % MOD;
                    }
                }
            }
        }
        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
    }
};
