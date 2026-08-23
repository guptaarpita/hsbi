class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        // Smallest Prime Factor
        vector<int> spf(mx + 1);

        for (int i = 0; i <= mx; i++)
            spf[i] = i;

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= mx; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        // Distinct prime factors of every number
        vector<vector<int>> factors(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];
                factors[i].push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        vector<int> freq(mx + 1, 0);

        int l = 0;
        int distinct = 0;
        int ans = 0;

        for (int r = 0; r < n; r++) {

            // Add nums[r]
            for (int p : factors[r]) {
                if (freq[p] == 0)
                    distinct++;

                freq[p]++;
            }

            // Too many distinct primes -> shrink
            while (distinct > k) {
                for (int p : factors[l]) {
                    freq[p]--;

                    if (freq[p] == 0)
                        distinct--;
                }

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};