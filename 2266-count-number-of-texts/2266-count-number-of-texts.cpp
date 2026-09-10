class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        long long ans = 1;

        for (int i = 0; i < n; ) {
            int j = i;

            // Find the end of the consecutive group
            while (j < n && pressedKeys[j] == pressedKeys[i]) {
                j++;
            }

            int len = j - i;
            int maxPress = (pressedKeys[i] == '7' || pressedKeys[i] == '9') ? 4 : 3;

            // dp[k] = number of ways to decode k identical presses
            vector<long long> dp(len + 1, 0);
            dp[0] = 1;

            for (int k = 1; k <= len; k++) {
                for (int take = 1; take <= maxPress && take <= k; take++) {
                    dp[k] = (dp[k] + dp[k - take]) % MOD;
                }
            }

            ans = (ans * dp[len]) % MOD;
            i = j;
        }

        return ans;
    }
};