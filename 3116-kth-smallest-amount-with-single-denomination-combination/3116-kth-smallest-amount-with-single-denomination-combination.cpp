class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](long long x) -> long long {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                long long lcm = 1;
                bool overflow = false;

                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        long long g = std::gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        if (lcm > x) {
                            overflow = true;
                            break;
                        }
                    }
                }

                if (overflow) continue;

                long long cnt = x / lcm;
                if (__builtin_popcount(mask) & 1)
                    ans += cnt;
                else
                    ans -= cnt;
            }

            return ans;
        };
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};