class Solution {
    bool checkIfIncreasing(vector<int>& nums, int min_idx, int n) {
        for (int i = 0; i < n; ++i) {
            int curr = (min_idx + i) % n;
            int next = (curr + 1) % n;
            if (nums[next] != (nums[curr] + 1) % n) {
                return false;
            }
        }
        return true;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                min_idx = i;
                break;
            }
        }
        bool is_increasing =
            checkIfIncreasing(nums, min_idx, n);
        bool is_decreasing = false;
        if (!is_increasing) {
            reverse(nums.begin(), nums.end());
            min_idx = n - min_idx - 1;
            is_decreasing =
                checkIfIncreasing(nums, min_idx, n);
        }if (!is_increasing && !is_decreasing) {
            return -1;
        }
        if (is_increasing) {
            return min(min_idx, 2 + n - min_idx);
        }
        return min(1 + min_idx, 1 + (n - min_idx));
    }
};
