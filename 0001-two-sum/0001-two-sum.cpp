class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        map<int, int> sum;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int more = target - num;
            if(sum.find(more) != sum.end()){
                return {sum[more], i};
            }
            sum[num] = i;
        }
        return {-1, -1};
    }
};