class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int j =0; j <=n; j++){
            for(int jump =1; jump <= 3 && jump <= j; jump++){
                int i = j -jump;
                    int total = dp[i] + costs[j-1] + jump * jump;
                    dp[j] = min(dp[j], total);
                }
            }
            return dp[n];
        }
        
         
};