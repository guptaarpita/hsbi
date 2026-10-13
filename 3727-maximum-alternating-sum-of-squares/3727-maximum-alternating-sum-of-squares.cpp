class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<int>pq;
        long long total = 0;
        for(int i = 0;i < nums.size();i++){
            total+=(nums[i]*nums[i]);
            pq.push(abs(nums[i]));
        } int k = nums.size();
        if(k%2==0){
            k = k/2;
        }else{
            k = k/2 +1;
        }
        long long sum = 0;
        for(int i = 0;i < k;i++){
            int x = pq.top();
            pq.pop();
            sum += x*x;
        }
        long long diff = total - sum;
        long long ans = sum - diff;

        return ans;

    }
};