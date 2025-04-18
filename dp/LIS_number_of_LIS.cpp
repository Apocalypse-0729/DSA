class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi=1;
        int ans=0;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i]>nums[prev] && dp[i]<(1+dp[prev])){
                    dp[i]=dp[prev]+1;
                    cnt[i]=cnt[prev];
                }
                else if(nums[i]>nums[prev] && dp[i]==(1+dp[prev])){
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        for(int i=0; i<n; i++){
            // cout<<dp[i]<<" ";
            if(dp[i]==maxi){
                ans+=cnt[i];
            }
        }
        // cout<<endl;
        return ans;
    }
};
