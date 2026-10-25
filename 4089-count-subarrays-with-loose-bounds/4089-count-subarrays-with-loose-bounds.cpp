class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans1 = 0;
        int n = nums.size();
        int left = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] < minK || nums[right] > maxK){
                left = right + 1;
            }
        ans1 += right - left + 1;
            
        }
        return ans1;
    }
};