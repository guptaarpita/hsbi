
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long count = 0;
        long long cost = 0;

        int right = n - 1;
        deque<int> leaders;

        for (int left = n - 1; left >= 0; left--) {

            while (!leaders.empty() &&
                   nums[leaders.back()] < nums[left]) {

                int j = leaders.back();
                leaders.pop_back();

                int end = leaders.empty()
                            ? right + 1
                            : leaders.back();

                cost += 1LL * (end - j) *
                        (nums[left] - nums[j]);
            }

            leaders.push_back(left);

            while (cost > k) {
                cost -= nums[leaders.front()] - nums[right];

                if (leaders.front() == right) {
                    leaders.pop_front();
                }

                right--;
            }

            count += right - left + 1;
        }

        return count;
    }
};
