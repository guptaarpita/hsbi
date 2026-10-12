class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int cnt[31] = {0};
        for (int i = 0; i < nums.size(); i++) {
            for (int b = 0; b < 31; b++) {
                if ((nums[i] >> b) & 1) {
                    cnt[b]++;
                }}}
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 30; b >= 0; b--) {
                if (cnt[b] > 0) {
                    val += (1LL << b);
                    cnt[b]--;
                }
            }
            ans = (ans + val * val) % (1000000007);
        }
        return ans;
    }
};