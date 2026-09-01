class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        if (k == 0) return 0;

        int fullMask = (1 << k) - 1;

        // litterIndex[r][c] = index of litter at (r,c), or -1.
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            auto [r, c] = litter[i];
            litterIndex[r][c] = i;
        }

        /*
            best[r][c][mask] = maximum energy remaining when
            reaching (r,c) after collecting 'mask'.

            If we reach the same state with less energy, ignore it.
        */
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct State {
            int r, c;
            int mask;
            int remEnergy;
            int moves;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy, 0});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, mask, remEnergy, moves] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid.
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle.
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need one energy to make a move.
                if (remEnergy == 0)
                    continue;

                int newEnergy = remEnergy - 1;
                int newMask = mask;

                // Collect litter.
                if (classroom[nr][nc] == 'L') {
                    int id = litterIndex[nr][nc];
                    newMask |= (1 << id);
                }

                // Reset area restores energy to maximum.
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }

                int newMoves = moves + 1;

                // All litter collected.
                if (newMask == fullMask)
                    return newMoves;

                /*
                    Dominance:
                    If we've already reached (nr,nc,newMask)
                    with at least as much energy, this state
                    cannot lead to a better answer.
                */
                if (newEnergy <= best[nr][nc][newMask])
                    continue;

                best[nr][nc][newMask] = newEnergy;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newEnergy,
                    newMoves
                });
            }
        }

        return -1;
    }
};