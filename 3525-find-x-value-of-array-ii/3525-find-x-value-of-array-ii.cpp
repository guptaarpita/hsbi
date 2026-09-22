class Solution {
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefix lies completely in left child
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefix contains all of left child + prefix of right child
        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.cnt[rem] += b.cnt[r];
        }

        return res;
    }

    Node makeNode(int val) {
        Node res;

        int rem = val % k;
        res.prod = rem;
        res.cnt[rem] = 1;

        return res;
    }

    void build(int p, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[p] = makeNode(nums[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(p * 2, l, mid, nums);
        build(p * 2 + 1, mid + 1, r, nums);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            seg[p] = makeNode(val);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(p * 2, l, mid, idx, val);
        else
            update(p * 2 + 1, mid + 1, r, idx, val);

        seg[p] = merge(seg[p * 2], seg[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(p * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(p * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(p * 2, l, mid, ql, qr);
        Node right = query(p * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

public:
    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        this->k = k;

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            nums[index] = value;
            update(1, 0, n - 1, index, value);

            // Remaining array is nums[start ... n-1].
            // Every possible operation leaves a non-empty prefix.
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};