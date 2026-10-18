class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int alpha = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(alpha, vector<bool>(n, false));

        int rat = 0; int cat =0;
        visited[rat][cat] = true;

        while(true){
            int nr = rat, nc = cat;
            char dir = grid[rat][cat];
            
            if(dir == 'L')nc--;
            else if(dir == 'R')nc++;
            else if(dir == 'U')nr--;
            else if(dir == 'D')nr++;

            if(nr < 0 || nr >= alpha || nc < 0 || nc >= n)
            break;
            if(visited[nr][nc])
            break;
            rat = nr;
            cat = nc;
            visited[rat][cat] = true;
        }
        return {rat, cat};
    }
};