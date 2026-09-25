class Solution {
public:
    string s;
    int i;

    set<string> parseExpression() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;
            auto t = parseTerm();
            res.insert(t.begin(), t.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur;

            if (s[i] == '{') {
                i++;
                cur = parseExpression();
                i++;
            } else {
                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> next;

            for (auto &a : res)
                for (auto &b : cur)
                    next.insert(a + b);

            res = std::move(next);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        auto ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};