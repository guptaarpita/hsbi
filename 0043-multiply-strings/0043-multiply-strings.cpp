class Solution {
public:
    string multiply(string a, string b) {
        if (a == "0" || b == "0") return "0";
        int n = a.size(), m = b.size();
        vector<int> res(n + m);
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--) {
                int p = (a[i] - '0') * (b[j] - '0');
                int k = i + j + 1;
                res[k] += p;
                res[k - 1] += res[k] / 10;
                res[k] %= 10;
            }
        string ans;
        for (int x : res)
            if (!ans.empty() || x) ans += '0' + x;
        return ans;
    }
};;