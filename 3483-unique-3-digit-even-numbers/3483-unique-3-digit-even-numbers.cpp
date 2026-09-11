class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int d : digits)
            cnt[d]++;

        int ans = 0;

        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;
            int freq[10] = {};

            for (int i = 0; i < 3; i++) {
                freq[x % 10]++;
                x /= 10;
            }

            bool possible = true;
            for (int d = 0; d <= 9; d++) {
                if (freq[d] > cnt[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};