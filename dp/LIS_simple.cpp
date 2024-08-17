class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int n=nums.size();
        int maxi=1; 
        for(int ind=0; ind<n; ind++){
            for(int prev_ind=0; prev_ind<ind; prev_ind++){
                if(nums[ind]>nums[prev_ind] && dp[ind]<dp[prev_ind]+1){
                    dp[ind]=dp[prev_ind]+1;
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};
