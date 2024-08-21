class Solution{
  public:
    int solve(int ind, int length, int price[], vector<vector<int>> &dp){
        if(ind==0){
            // Means piece of Length one
            return length*price[0];
        }
        
        if(dp[ind][length]!=-1) return dp[ind][length];
        
        int notake=0+solve(ind-1,length,price,dp);
        int take=INT_MIN;
        if(length>=ind+1){
            take=price[ind]+solve(ind,length-ind-1,price,dp);
        }
        return dp[ind][length]=max(take,notake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(n-1,n,price,dp);
    }
};
