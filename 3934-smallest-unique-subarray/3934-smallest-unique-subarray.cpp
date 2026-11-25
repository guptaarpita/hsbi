
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), r(n), nr(n), tmp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            r[i] = nums[i];
        }

        // Build suffix array using doubling
        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (r[a] != r[b])
                    return r[a] < r[b];

                int x = (a + k < n) ? r[a + k] : -1;
                int y = (b + k < n) ? r[b + k] : -1;

                return x < y;
            });

            nr[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];

                bool diff = r[a] != r[b];

                int x = (a + k < n) ? r[a + k] : -1;
                int y = (b + k < n) ? r[b + k] : -1;

                if (x != y) diff = true;

                nr[b] = nr[a] + diff;
            }

            r = nr;

            if (r[sa[n - 1]] == n - 1)
                break;
        }

        // Kasai's algorithm for LCP
        vector<int> pos(n), lcp(n, 0);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            if (pos[i] == 0) continue;

            int j = sa[pos[i] - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h])
                h++;

            lcp[pos[i]] = h;

            if (h > 0) h--;
        }
        int ans = n;

        for (int i = 0; i < n; i++) {
            int need = 1;

            if (i > 0)
                need = max(need, lcp[i] + 1);

            if (i + 1 < n)
                need = max(need, lcp[i + 1] + 1);

            if (sa[i] + need <= n)
                ans = min(ans, need);
        }

        return ans;
    }
};
