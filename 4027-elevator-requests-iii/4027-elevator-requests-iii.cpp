class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        
       
        vector<int> floors;
        floors.push_back(start);
        for (auto &r : requests) floors.push_back(r[1]);

        int K = floors.size();
        int FULL = (1 << m) - 1;

        vector<int> at(K, 0);
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < m; ++j) {
                if (floors[i] == requests[j][1])
                    at[i] |= (1 << j);
            }
        }

        auto fulfillAt = [&](int mask, int pos, long long t) {
            for (int j = 0; j < m; ++j) {
                if (!(mask & (1 << j)) &&
                    requests[j][1] == floors[pos] &&
                    requests[j][0] <= t) {
                    mask |= (1 << j);
                }
            }
            return mask;
        };

        
        const long long INF = (1LL << 62);
        vector<vector<long long>> dist(1 << m, vector<long long>(K, INF));

       
        int initialMask = fulfillAt(0, 0, 0);
        dist[initialMask][0] = 0;

        using State = tuple<long long, int, int>; // time, mask, position
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, initialMask, 0});

        while (!pq.empty()) {
            auto [t, mask, p] = pq.top();
            pq.pop();

            if (t != dist[mask][p])
                continue;

            if (mask == FULL)
                return t;

            for (int q = 0; q < K; ++q) {
                if (q == p) continue;

                long long nt = t + llabs((long long)floors[p] - floors[q]);
                int nmask = mask;

               
                for (int j = 0; j < m; ++j) {
                    if (nmask & (1 << j)) continue;

                    long long f = requests[j][1];

                    if (f < min(floors[p], floors[q]) ||
                        f > max(floors[p], floors[q]))
                        continue;

                    long long reachTime =
                        t + llabs(f - (long long)floors[p]);

                    if (requests[j][0] <= reachTime)
                        nmask |= (1 << j);
                }

                nmask = fulfillAt(nmask, q, nt);

                if (nt < dist[nmask][q]) {
                    dist[nmask][q] = nt;
                    pq.push({nt, nmask, q});
                }
            }

           
            long long waitUntil = INF;

            for (int j = 0; j < m; ++j) {
                if (!(mask & (1 << j)) &&
                    requests[j][1] == floors[p] &&
                    requests[j][0] > t) {
                    waitUntil = min(waitUntil, (long long)requests[j][0]);
                }
            }

            if (waitUntil != INF) {
                int nmask = fulfillAt(mask, p, waitUntil);

                if (waitUntil < dist[nmask][p]) {
                    dist[nmask][p] = waitUntil;
                    pq.push({waitUntil, nmask, p});
                }
            }
        }

        return -1; 
    }
};