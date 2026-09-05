class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int, int> mp;
        for (int r : ranks) mp[r]++;

        if (set<char>(suits.begin(), suits.end()).size() == 1)
            return "Flush";

        for (auto &[r, cnt] : mp) {
            if (cnt >= 3)
                return "Three of a Kind";
        }

        for (auto &[r, cnt] : mp) {
            if (cnt >= 2)
                return "Pair";
        }

        return "High Card";
    }
};