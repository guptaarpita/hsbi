class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>result;
        string sam(n, '.');
        result.push_back(sam);
        for(int i = 1; i< m; i++){
            string s(n, '#');
            s[n-1]='.';
            result.push_back(s);
        }
        return result;
    }
};