class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> id(n);
        iota(id.begin(),id.end(),0);

        sort(id.begin(),id.end(),[&](int i,int j){
            return a[i][1]<a[j][1];
        });

        vector<int> ends(n);
        for(int i=0;i<n;i++) ends[i]=a[id[i]][1];

        vector<vector<pair<long long,vector<int>>>> dp(
            5, vector<pair<long long,vector<int>>>(n+1));

        for(int i=1;i<=n;i++){
            int x=id[i-1];

            int p=lower_bound(ends.begin(),ends.begin()+i-1,a[x][0])
                  -ends.begin();

            for(int k=1;k<=4;k++){
                dp[k][i]=dp[k][i-1];

                auto q=dp[k-1][p];
                q.first+=a[x][2];
                q.second.push_back(x);
                sort(q.second.begin(),q.second.end());

                if(q.first>dp[k][i].first ||
                  (q.first==dp[k][i].first &&
                   q.second<dp[k][i].second))
                    dp[k][i]=q;
            }
        }

        return dp[4][n].second;
    }
};