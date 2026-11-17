#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long int ll;

class Solution {
public:
    int check(string b) {
        int n = b.size();
        int sum = 0;
        for (int i = 0; i < n / 2; i++) {
            if (b[i] != b[n - i - 1]) {
                sum++;
            }
        }
        return sum;
    }
    int getChanges(string &s, int l, int r, int d) {
        int changes = 0;
        for (int rem = 0; rem < d; rem++) {
            string group = "";
            for (int i = l + rem; i <= r; i += d) {
                group += s[i];
            }
            changes += check(group);
        }
        return changes;
    }
    int minimumChanges(string s, int K) {
        int n = s.size();
        vector<int> divisors[n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    divisors[i].push_back(j);
                    if (j != 1 && j * j != i) {
                        divisors[i].push_back(i / j);
                    }
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int min_c = 1e8;
                for (int d : divisors[len]) {
                    if (d < len) {
                        min_c = min(min_c, getChanges(s, i, j, d));
                    }
                }
                cost[i][j] = min_c;
            }
        }
        vector<vector<int>> dp(n, vector<int>(K + 1, 1e8));
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
            for (int k = 2; k <= K; k++) {
                for (int j = k - 1; j <= i; j++) {
                    if (j - 1 >= 0) {
                        dp[i][k] = min(dp[i][k], cost[j][i] + dp[j - 1][k - 1]);
                    }
                }
            }
        }
        return dp[n - 1][K];
    }
};