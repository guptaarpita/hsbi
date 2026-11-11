class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res = LLONG_MAX;
        res = min(res, 1LL * cost1 * need1 + 1LL * cost2 * need2);
        res = min(res, 1LL * costBoth * max(need1, need2));
        if (need1 < need2) res = min(res, 1LL * costBoth * need1 + 1LL * cost2 * (need2 - need1));
        else res = min(res, 1LL * costBoth * need2 + 1LL * cost1 * (need1 - need2));
        return res;
    }
};