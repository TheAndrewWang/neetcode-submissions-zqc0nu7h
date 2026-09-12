class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numIslands = 0; 

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return numIslands; 
    }

    void dfs(vector<vector<char>>& grid2, int r, int c, int m, int n){
        if(r < 0 || c >= n || r >= m || c < 0 || grid2[r][c] == '0') {
            return; 
        } // boundary + water 
        grid2[r][c] = '0';

        // dfs 
        dfs(grid2, r+ 1, c, m, n);
        dfs(grid2, r, c + 1, m, n);
        dfs(grid2, r - 1, c, m, n);
        dfs(grid2, r, c - 1, m, n);
    }
};
