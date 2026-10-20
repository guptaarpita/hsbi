class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool valid = true;
            int prevMax = -1;
            for (int i = 0; i < n; i += k) {
                int descents = 0, pivot = -1;
                for (int j = 0; j < k; j++) {
                    int next = (j + 1) % k;
                    if (nums[i + j] > nums[i + next]) {
                        descents++;
                        pivot = j;
                    }
                }
                if (descents > 1) {
                    valid = false;
                    break;
                }
                int first, last;
                if (pivot != -1) {
                    first = nums[i + (pivot + 1) % k];
                    last = nums[i + pivot];
                } else {
                    first = nums[i];
                    last = nums[i + k - 1];
                }
                if (prevMax > first) {
                    valid = false;
                    break;
                }
                prevMax = last;
            }
            if (valid) ans += k;
        }
        return ans;
    }
};