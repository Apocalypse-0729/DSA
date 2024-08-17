class Solution {
public:
    int LIS(int ind, int prev_ind, vector<int> &arr, vector<vector<int>> &dp){
        int n=arr.size();
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int notake=0+LIS(ind+1,prev_ind,arr,dp);
        int take=INT_MIN;
        if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
            take=1+LIS(ind+1,ind,arr,dp);
        }
        return dp[ind][prev_ind+1]=max(notake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp);
    }
};
