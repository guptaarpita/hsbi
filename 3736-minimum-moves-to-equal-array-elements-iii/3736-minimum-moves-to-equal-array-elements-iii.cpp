class Solution {
public:
    int minMoves(vector<int>& nums) {
        int largest = nums[0];
        for(int x : nums){
            if(x > largest)
            largest = x;
        }
        int moves = 0;
        for(int x : nums){
            moves += largest - x;

        }
        return moves;
    }
};