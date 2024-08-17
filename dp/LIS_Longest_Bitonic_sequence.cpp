vector<int> lengthOfLIS1(vector<int>& nums) {
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
        return dp;
    }
    vector<int> lengthOfLIS2(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int n=nums.size();
        int maxi=1; 
        for(int ind=n-1; ind>=0; ind--){
            for(int prev_ind=n-1; prev_ind>ind; prev_ind--){
                if(nums[ind]>nums[prev_ind] && dp[ind]<dp[prev_ind]+1){
                    dp[ind]=dp[prev_ind]+1;
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return dp;
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1=lengthOfLIS1(nums);
        // reverse(nums.begin(),nums.end());
        vector<int> dp2=lengthOfLIS2(nums);
        int maxi=0;
        for(int i=0; i<n; i++){
            if(dp1[i] == 1 or dp2[i] == 1) continue;
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
