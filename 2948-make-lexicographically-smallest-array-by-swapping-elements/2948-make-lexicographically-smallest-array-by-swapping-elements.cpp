class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> ans = nums;

        int l = 0;

        while (l < n) {
            int r = l;

            while (r + 1 < n && 
                   (long long)a[r + 1].first - a[r].first <= limit) {
                r++;
            }

            vector<int> indices;
            for (int i = l; i <= r; i++)
                indices.push_back(a[i].second);

            sort(indices.begin(), indices.end());

            for (int i = 0; i <= r - l; i++)
                ans[indices[i]] = a[l + i].first;

            l = r + 1;
        }

        return ans;
    }
};