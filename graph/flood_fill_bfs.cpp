class Solution {
public:
    void dfs(int r, int c, int oldColor,int newColor, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[r][c] = 1;
        grid[r][c] = newColor;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = r + dx[i];
            int ncol = c + dy[i];
            if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col &&!vis[nrow][ncol] && grid[nrow][ncol]==oldColor) {
                dfs(nrow, ncol,oldColor, newColor, vis, grid);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int newColor) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int oldColor = grid[sr][sc];
        if (oldColor == newColor) {
            return grid;
        }
        dfs(sr, sc,oldColor,newColor, vis, grid);
        return grid;
    }
};
