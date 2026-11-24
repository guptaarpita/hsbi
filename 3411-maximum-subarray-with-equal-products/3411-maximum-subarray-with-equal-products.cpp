class Solution {
public:
    int maxLength(vector<int>& nums) {
        int primes[4] = {2,3,5,7};
        int last[4] = {-1, -1, -1, -1};
        int best = 2;
        int left = 0;
        for(int right = 0; right<nums.size(); right++){
            for(int k = 0; k < 4; k++){
                if(nums[right] % primes[k] == 0){
                    left = max(left, last[k] + 1);
                    last[k] = right;
                }
            }
            best = max(best, right - left +1);
        }
        return best;
    }
};