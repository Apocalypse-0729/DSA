class Solution {
public:
    int pathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        int n=grid.size();
        int m=grid[n-1].size();
        if(i==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int pathsum1=grid[i][j]+pathSum(i+1,j+1,grid,dp);
        int pathsum2=grid[i][j]+pathSum(i+1,j,grid,dp);
        return dp[i][j]=min(pathsum1,pathsum2);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[n-1].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return pathSum(0,0,grid,dp);
    }
};
