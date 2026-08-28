class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0, mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                odd++;
                mid = i;
            }
        }

        if (odd > 1)
            return "";

        int m = n / 2;
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        string t = target.substr(0, m);

        for (int i = m; i >= 0; i--) {
            vector<int> rem = halfCnt;
            string half;
            bool ok = true;

            for (int j = 0; j < i; j++) {
                int c = t[j] - 'a';

                if (rem[c] == 0) {
                    ok = false;
                    break;
                }

                half += t[j];
                rem[c]--;
            }

            if (!ok)
                continue;

            if (i == m) {
                string cur = build(half, mid);
                if (cur > target)
                    return cur;
                continue;
            }

            int x = t[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string cur = half;
                cur += char('a' + c);
                rem[c]--;

                for (int k = 0; k < 26; k++)
                    cur += string(rem[k], char('a' + k));

                return build(cur, mid);
            }
        }

        return "";
    }

private:
    string build(const string& half, int mid) {
        string res = half;

        if (mid != -1)
            res += char('a' + mid);

        for (int i = (int)half.size() - 1; i >= 0; i--)
            res += half[i];

        return res;
    }
};