class Solution {
public:
    typedef pair<int, int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i = 0; i < k; i++) {
            available_servers.insert(i);
        }
        priority_queue<P, vector<P>, greater<P>> busyServers;

        vector<int> countRequest(k, 0);

        for(int i = 0; i < arrival.size(); i++) {
            int time = arrival[i];
            // Free all servers whose requests have completed
            while(!busyServers.empty() && busyServers.top().first <= time) {
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }
            // If no server is available, drop the request
            if(available_servers.empty()) {
                continue;
            }
            int target = i % k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()) {
                it = available_servers.begin();
            }

            int targetServer = *it;

            available_servers.erase(it);
            busyServers.push({time + load[i], targetServer});

            countRequest[targetServer]++;
        }
        int maxNumberOfRequest =
            *max_element(countRequest.begin(), countRequest.end());
        vector<int> result;

        for(int i = 0; i < k; i++) {
            if(countRequest[i] == maxNumberOfRequest) {
                result.push_back(i);
            }
        }
        return result;
    }
};
