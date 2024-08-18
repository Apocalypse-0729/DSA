class Solution {
public:
    int fun(int ind, int buy, int chance, vector<int> &nums, vector<vector<vector<int>>> &dp){
        int n=nums.size();
        if(ind==n || chance ==0) return 0;
        if(dp[ind][buy][chance]!=-1) return dp[ind][buy][chance];
        int profit=0;
        if(buy){
            profit=max(fun(ind+1,0,chance,nums,dp)-nums[ind],fun(ind+1,1,chance,nums,dp));
        }
        else{
            profit=max(fun(ind+1,1,chance-1,nums,dp)+nums[ind],fun(ind+1,0,chance,nums,dp));
        }
        return dp[ind][buy][chance]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0,1,2,prices,dp);
    }
};
