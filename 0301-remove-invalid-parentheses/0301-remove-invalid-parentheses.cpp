class Solution {
public:
    unordered_set<string> seen;
    vector<string> ans;

    void dfs(const string& s, int pos, int leftRem, int rightRem,
             int balance, string& cur) {

        if (pos == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0) {
                if (seen.insert(cur).second) {
                    ans.push_back(cur);
                }
            }
            return;
        }

        char c = s[pos];

        // Keep a letter
        if (c != '(' && c != ')') {
            cur.push_back(c);
            dfs(s, pos + 1, leftRem, rightRem, balance, cur);
            cur.pop_back();
            return;
        }

        // Remove current '('
        if (c == '(' && leftRem > 0) {
            dfs(s, pos + 1, leftRem - 1, rightRem, balance, cur);
        }

        // Remove current ')'
        if (c == ')' && rightRem > 0) {
            dfs(s, pos + 1, leftRem, rightRem - 1, balance, cur);
        }

        // Keep current '('
        if (c == '(') {
            cur.push_back('(');
            dfs(s, pos + 1, leftRem, rightRem, balance + 1, cur);
            cur.pop_back();
        }

        // Keep current ')'
        else {
            // A ')' can only be kept if there is a matching '('
            if (balance > 0) {
                cur.push_back(')');
                dfs(s, pos + 1, leftRem, rightRem, balance - 1, cur);
                cur.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0;
        int rightRem = 0;

        // Calculate minimum removals.
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string cur;
        dfs(s, 0, leftRem, rightRem, 0, cur);

        return ans;
    }
};