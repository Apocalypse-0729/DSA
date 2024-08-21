int func(int i, int sum, int wt[],int val[],vector<vector<int>> &dp){
        if(i==0){
            return (sum/wt[0])*val[0];
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notake=func(i-1,sum,wt,val,dp);
        int take=INT_MIN;
        if(wt[i]<=sum){
            take=val[i]+func(i,sum-wt[i],wt,val,dp);
        }
        return dp[i][sum]=max(take,notake);
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return func(N-1,W,wt,val,dp);
        
    }
