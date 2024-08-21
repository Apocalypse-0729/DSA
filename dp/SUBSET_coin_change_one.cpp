class Solution {
public:
    int func(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(i==0){
            if(sum%nums[0]==0) return sum/nums[0];
            return 1e9;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notake=func(i-1,sum,nums,dp);
        int take=1e9;
        if(nums[i]<=sum){
            take=1+func(i,sum-nums[i],nums,dp);
        }
        return dp[i][sum]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans= func(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};
