class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> available;
        priority_queue<tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>> busy;

        int n = servers.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();

                available.push({weight, idx});
            }
            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();

                    available.push({weight, idx});
                }
            }
            auto [weight, idx] = available.top();
            available.pop();

            ans.push_back(idx);

            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
