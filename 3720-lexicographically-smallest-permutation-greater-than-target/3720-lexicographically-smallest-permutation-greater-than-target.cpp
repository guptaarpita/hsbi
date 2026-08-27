class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;

        int n = s.size();
        int best = -1, bestChar = -1;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c]) {
                    best = i;
                    bestChar = c;
                    break;
                }
            }

            if (!cnt[x])
                break;

            cnt[x]--;
        }

        if (best == -1)
            return "";

        int x = target[best] - 'a';

        int freq[26] = {};
        for (char c : s)
            freq[c - 'a']++;

        for (int i = 0; i < best; i++)
            freq[target[i] - 'a']--;

        freq[bestChar]--;

        string ans = target.substr(0, best);
        ans += char('a' + bestChar);

        for (int c = 0; c < 26; c++)
            ans.append(freq[c], char('a' + c));

        return ans;
    }
};