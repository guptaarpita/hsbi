class Solution {
private:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    vector<int> seg;
    int timer;

    int dfsSize(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sz = dfsSize(v, u);
            subtree[u] += sz;

            if (sz > maxSize) {
                maxSize = sz;
                heavy[u] = v;
            }
        }

        return subtree[u];
    }

    void decompose(int u, int h, string &s) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h, s);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, s);
        }
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            // Find the node corresponding to this position.
            return;
        }
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int rangeQuery(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) / 2;
        return rangeQuery(node * 2, l, mid, ql, qr)
             ^ rangeQuery(node * 2 + 1, mid + 1, r, ql, qr);
    }

    int pathQuery(int u, int v, int n) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= rangeQuery(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v]) swap(u, v);

        mask ^= rangeQuery(1, 0, n - 1, pos[u], pos[v]);
        return mask;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        parent.resize(n);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        subtree.resize(n);
        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsSize(0, -1);
        decompose(0, 0, s);

        seg.assign(4 * n, 0);

        for (int u = 0; u < n; ++u)
            update(1, 0, n - 1, pos[u], 1 << (s[u] - 'a'));

        vector<bool> ans;

        for (const string &q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int v;
                ss >> v;
                int mask = pathQuery(u, v, n);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};