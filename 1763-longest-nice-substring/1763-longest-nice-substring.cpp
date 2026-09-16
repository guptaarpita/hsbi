class Solution {
public:
    string solve(const string& s, int l, int r) {
        if (r - l + 1 < 2)
            return "";

        // Record which letters appear in s[l..r].
        bool present[26] = {};

        for (int i = l; i <= r; ++i) {
            char c = s[i];
            if (c >= 'a' && c <= 'z')
                present[c - 'a'] = true;
            else
                present[c - 'A'] = true;
        }

        // Find a character whose opposite case is missing.
        for (int i = l; i <= r; ++i) {
            char c = s[i];
            int x = (c >= 'a' && c <= 'z')
                        ? c - 'a'
                        : c - 'A';

            // Check whether both lowercase and uppercase exist.
            bool hasLower = false, hasUpper = false;

            for (int j = l; j <= r; ++j) {
                if (tolower(s[j]) - 'a' == x) {
                    if (islower(s[j]))
                        hasLower = true;
                    else
                        hasUpper = true;
                }
            }

            if (!hasLower || !hasUpper) {
                // No valid nice substring can contain s[i].
                string left = solve(s, l, i - 1);
                string right = solve(s, i + 1, r);

                if (left.size() >= right.size())
                    return left;
                return right;
            }
        }
        return s.substr(l, r - l + 1);
    }

    string longestNiceSubstring(string s) {
        return solve(s, 0, s.size() - 1);
    }
};