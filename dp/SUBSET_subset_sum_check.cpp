bool func(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum==0) return true;
        if(i==0) return sum==arr[0];
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool notake=func(i-1,sum,arr,dp);
        bool take=false;
        if(arr[i]<=sum){
            take=func(i-1,sum-arr[i],arr,dp);
        }
        return dp[i][sum]=take | notake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
    }
