class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int deletion = 0;
        int l = nums[0];

        for(int i = 1; i <nums.size(); i++){
            if(nums[i] == l){
                deletion++;
            }else{
                l = nums[i];
            }
        }
        
        
        return deletion;
    }
};