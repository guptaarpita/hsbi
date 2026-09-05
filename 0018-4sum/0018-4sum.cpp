class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Smallest possible sum is already too large
            if ((long long)nums[i] + nums[i + 1] +
                nums[i + 2] + nums[i + 3] > target)
                break;

            // Largest possible sum is still too small
            if ((long long)nums[i] + nums[n - 1] +
                nums[n - 2] + nums[n - 3] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Smallest possible sum for this j
                if ((long long)nums[i] + nums[j] +
                    nums[j + 1] + nums[j + 2] > target)
                    break;

                // Largest possible sum for this j
                if ((long long)nums[i] + nums[j] +
                    nums[n - 1] + nums[n - 2] < target)
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[left]
                                  + nums[right];

                    if (sum == target) {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // Skip duplicate left values
                        while (left < right &&
                               nums[left] == nums[left + 1])
                            left++;

                        // Skip duplicate right values
                        while (left < right &&
                               nums[right] == nums[right - 1])
                            right--;

                        left++;
                        right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};