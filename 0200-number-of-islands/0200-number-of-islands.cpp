class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j,int n,int m){
        grid[i][j] = '0';
        vector<int> ni = {1,0,-1,0};
        vector<int> nj = {0,-1,0,1};
        for(int k=0;k<4;k++){
            int nii = ni[k] + i; 
            int njj = nj[k] + j; 
            if(nii>=0 && nii <n && njj >=0 && njj < m && grid[nii][njj] == '1' ){
                dfs(grid,nii,njj,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int cn=0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== '1'){
                    dfs(grid,i,j,n,m); 
                    cn++; 
                }
            }
        }
        return cn; 
    }
};