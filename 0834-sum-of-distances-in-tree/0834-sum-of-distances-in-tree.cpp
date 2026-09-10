class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sub, ans;
    int n;

    void dfs1(int u, int p) {
        sub[u] = 1;

        for (int v : adj[u]) {
            if (v == p) continue;

            dfs1(v, u);
            sub[u] += sub[v];
            ans[0] += sub[v];
        }
    }

    void dfs2(int u, int p) {
        for (int v : adj[u]) {
            if (v == p) continue;

            ans[v] = ans[u] + n - 2 * sub[v];
            dfs2(v, u);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        sub.resize(n);
        ans.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};