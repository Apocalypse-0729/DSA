class Solution {
public:
    int fun(int ind, int buy,int fee, vector<int> &nums, vector<vector<int>> &dp ){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(fun(ind+1,0,fee,nums,dp)-nums[ind],fun(ind+1,1,fee,nums,dp));
        } 
        else{
            profit=max(fun(ind+1,1,fee,nums,dp)+nums[ind]-fee,fun(ind+1,0,fee,nums,dp));
        }
        return dp[ind][buy]=profit;
    }   
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return fun(0,1,fee,prices,dp);
    }
};
