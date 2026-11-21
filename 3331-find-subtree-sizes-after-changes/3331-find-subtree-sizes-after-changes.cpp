class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> old_adj(n), new_adj(n);

        for (int i = 1; i < n; i++) {
            old_adj[parent[i]].push_back(i);
        }

        function<void(int, array<int, 26>)> dfs =
            [&](int cur, array<int, 26> node) {

                int c = s[cur] - 'a';

                if (node[c] != -1) {
                    new_adj[node[c]].push_back(cur);
                } 
                else if (cur != 0) {
                    new_adj[parent[cur]].push_back(cur);
                }

                node[c] = cur;

                for (auto u : old_adj[cur]) {
                    dfs(u, node);
                }
            };

        array<int, 26> last;
        last.fill(-1);

        dfs(0, last);

        vector<int> ans(n);

        function<void(int)> dfs1 = [&](int cur) {
            ans[cur] = 1;

            for (auto u : new_adj[cur]) {
                dfs1(u);
                ans[cur] += ans[u];
            }
        };

        dfs1(0);

        return ans;
    }
};
