class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // dp[i] = maximum score difference the current player
        // can achieve starting from index i.
        vector<int> dp(n + 1, 0);

        // No stones left => score difference is 0.
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            int sum = 0;

            // Try taking 1, 2, or 3 stones.
            dp[i] = INT_MIN;

            for (int k = 1; k <= 3 && i + k <= n; k++) {
                sum += stoneValue[i + k - 1];

                // We get 'sum', but the opponent can get
                // dp[i + k] advantage from the remaining stones.
                dp[i] = max(dp[i], sum - dp[i + k]);
            }
        }

        if (dp[0] > 0)
            return "Alice";
        else if (dp[0] < 0)
            return "Bob";
        else
            return "Tie";
    }
};