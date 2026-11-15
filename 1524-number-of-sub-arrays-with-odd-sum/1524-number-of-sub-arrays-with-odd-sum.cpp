class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long cur_sum = 0;
        long long odd_cnt = 0;
        long long even_cnt = 1;
        long long res = 0;
        const int MOD = 1e9 + 7;
        for (int n : arr) {
            cur_sum += n;
            if (cur_sum % 2 != 0) {
                res = (res + 1 + even_cnt - 1) % MOD;
                odd_cnt++;
            } else {
                res = (res + odd_cnt) % MOD;
                even_cnt++;
            }}
        return res;
    }
};