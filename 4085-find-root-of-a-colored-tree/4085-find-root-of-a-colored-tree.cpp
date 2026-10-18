class Solution {
public:
    int findColoredRoot(vector<vector<int>>& e, string c) {
        int n = c.size();
        vector<vector<int>> G(n);
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < e.size(); i++) {
            int x = e[i][0];
            int y = e[i][1];

            if (c[x] == 'R' && c[y] == 'B') {
                G[x].push_back(y);
            }
            if (c[x] == 'B' && c[y] == 'R') {
                G[y].push_back(x);
            }
            if (c[x] == 'B' && c[y] == 'W') {
                G[x].push_back(y);
            }
            if (c[x] == 'W' && c[y] == 'B') {
                G[y].push_back(x);
            }
            if (c[x] == 'W' && c[y] == 'R') {
                G[x].push_back(y);
            }
            if (c[x] == 'R' && c[y] == 'W') {
                G[y].push_back(x);
            }
        }
        for (int i = 0; i < n; i++) {
            for (auto u : G[i]) {
                indegree[u]++;
                outdegree[i]++;
            }
        }
        int count = 0;
        int answer = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                answer = i;
                count++;
            }
        }
        if (count != 1) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            if (outdegree[i] >= 3) {
                return -1;
            }
        }
        return answer;
    }
};