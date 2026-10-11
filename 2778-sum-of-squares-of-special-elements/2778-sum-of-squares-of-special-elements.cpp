class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int s = nums.size();
        int ans = 0;
        for(int i = 1; i <= s; i++){
            if(s % i == 0){
                ans += nums[i-1]* nums[i-1];
            }
        }
        return ans;
    }
};