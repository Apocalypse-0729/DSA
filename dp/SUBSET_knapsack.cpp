class Solution {
public:
    const int mod=1e9+7;
    int func(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(i==0){
            return (sum%nums[0]==0);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notake=func(i-1,sum,nums,dp);
        int take=0;
        if(nums[i]<=sum){
            take=func(i,sum-nums[i],nums,dp);
        }
        return dp[i][sum]=(take+notake);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans= func(n-1,amount,coins,dp);
        return ans;
    }
};
