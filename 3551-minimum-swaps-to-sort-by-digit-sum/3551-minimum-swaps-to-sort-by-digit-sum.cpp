class Solution {
public:

int getDigitSum(int num){
    int sum = 0;
    while(num > 0 ){
        sum +=(num % 10);
        num /= 10;
    }
    return sum;
}
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2){
            int num1DigitSum = getDigitSum(num1);
            int num2DigitSum = getDigitSum(num2);

            if(num1DigitSum != num2DigitSum){
                return num1DigitSum < num2DigitSum;
            }
            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda);

        unordered_map<int, int> val2idx;
        for(int i=0; i < n; i++ ){
            val2idx[nums[i]] = i;
        }

        int swapCount = 0;
        for(int i =0; i < n; i++){
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if(expectedVal == currVal)
            continue;

            int idx = val2idx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currVal;

            val2idx[expectedVal] = i;
            val2idx[currVal] = idx;

            swapCount++;
        }
        return swapCount;
    }
};