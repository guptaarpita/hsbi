class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peaksum = 0;
        int valley = 0;
        int n = nums.size();
        int i = 1;
        while (i < n - 1) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peaksum += nums[i];
            }
            else {
                if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                    valley += nums[i];
                }
            }
            i++;
        }
        return peaksum - valley;
    }
};
