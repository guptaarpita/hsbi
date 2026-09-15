class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (cur.empty() || cur == ".") {
                    // Ignore
                } else if (cur == "..") {
                    if (!st.empty())
                        st.pop_back();
                } else {
                    st.push_back(cur);
                }

                cur.clear();
            } else {
                cur += path[i];
            }
        }

        string ans = "/";

        for (int i = 0; i < st.size(); i++) {
            ans += st[i];
            if (i + 1 < st.size())
                ans += "/";
        }

        return ans;
    }
};