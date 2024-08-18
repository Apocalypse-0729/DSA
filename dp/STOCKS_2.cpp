class Solution {
public:
    int fun(int ind, int buy, vector<int> &nums, vector<vector<int>> &dp ){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(fun(ind+1,0,nums,dp)-nums[ind],fun(ind+1,1,nums,dp));
        } 
        else{
            profit=max(fun(ind+1,1,nums,dp)+nums[ind],fun(ind+1,0,nums,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};
