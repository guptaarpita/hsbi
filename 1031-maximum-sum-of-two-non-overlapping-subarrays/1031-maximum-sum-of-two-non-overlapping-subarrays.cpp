class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();
        vector<int> p(n + 1);

        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + nums[i];

        auto solve = [&](int A, int B) {
            int best = 0, ans = 0;

            for (int i = A; i + B <= n; i++) {
                best = max(best, p[i] - p[i - A]);
                ans = max(ans, best + p[i + B] - p[i]);
            }

            return ans;
        };

        return max(solve(L, M), solve(M, L));
    }
};