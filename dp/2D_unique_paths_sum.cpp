class Solution {
public:
    int pathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int pathsum1=grid[i][j]+pathSum(i-1,j,grid,dp);
        int pathsum2=grid[i][j]+pathSum(i,j-1,grid,dp);
        return dp[i][j]=min(pathsum1,pathsum2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return pathSum(n-1,m-1,grid,dp);
    }
};
