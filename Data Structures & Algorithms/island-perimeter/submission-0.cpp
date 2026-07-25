class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false)); 
        int p = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, visited, p, {i, j});
                    return p;
                }
            }
        }

    }

    void dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int& perimeter, pair<int, int> current) {
        if (current.first < 0 || current.second < 0 || current.first >= grid.size() || current.second >= grid[0].size()) {
            perimeter++;
            return;
        }
        if (visited[current.first][current.second] == true && grid[current.first][current.second] == 1) {
            return;
        } else {
            visited[current.first][current.second] = true;
        }
        if (grid[current.first][current.second] == 0) {
            perimeter++;
            return;
        }
        dfs(grid, visited, perimeter, {current.first + 1, current.second});
        dfs(grid, visited, perimeter, {current.first - 1, current.second});
        dfs(grid, visited, perimeter, {current.first, current.second + 1});
        dfs(grid, visited, perimeter, {current.first, current.second - 1});
    }
};