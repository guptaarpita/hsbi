const int mod = 1e9 + 7;
const int N = 1e5 + 10;
using LL = long long;

class Solution {
public:
    int f[N], s[N];
    struct Node {
        int l, r;
        LL sum;
        int add;
    } tr[N << 2];
    void build(int u, int l, int r) {
        if (l == r)
            tr[u] = {l, r, 0, 0};
        else {
            tr[u] = {l, r, 0, 0};
            int mid = l + r >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
            pushup(u);
        }
    }
    void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }

    void pushdown(int u) {
        auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        if (root.add) {
            left.add += root.add,
                left.sum += (LL)(left.r - left.l + 1) * root.add;
            right.add += root.add,
                right.sum += (LL)(right.r - right.l + 1) * root.add;
            root.add = 0;
        }
    }
    void modify(int u, int l, int r, int v) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].add += 1;
            tr[u].sum += tr[u].r - tr[u].l + 1;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (mid >= l)
            modify(u << 1, l, r, v);
        if (mid < r)
            modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
    LL query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].sum;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        LL sum = 0;
        if (l <= mid)
            sum = query(u << 1, l, r);
        if (r > mid)
            sum += query(u << 1 | 1, l, r);
        return sum;
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        build(1, 1, n);
        vector<int> a(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            a[i + 1] = nums[i];
        }
        map<int, int> hash;
        for (int i = 1; i <= n; ++i) {
            if (!hash.count(a[i])) {
                int len = i;
                s[i] = (s[i - 1] + 2ll * query(1, 1, i) % mod + len) % mod;
                f[i] = (f[i - 1] + s[i]) % mod;
                modify(1, 1, i, 1);
            } else {
                int len = i - hash[a[i]];
                s[i] =
                    (s[i - 1] + 2ll * query(1, hash[a[i]] + 1, i) + len) % mod;
                f[i] = (f[i - 1] + s[i]) % mod;
                modify(1, hash[a[i]] + 1, i, 1);
            }
            hash[a[i]] = i;
        }
        return f[n];
    }
};
