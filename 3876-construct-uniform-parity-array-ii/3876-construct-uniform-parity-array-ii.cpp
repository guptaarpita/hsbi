class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());
        if (mn % 2 == 0) {
            for (int y : nums1) {
                if (y % 2 != 0)
                    return false;
            }
            return true;
        }
        return true;
    }
};