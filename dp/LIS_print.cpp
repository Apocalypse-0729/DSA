vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n);
        int lastIndex=0;
        int maxi=1;
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(arr[i]>arr[prev] && dp[i]<(1+dp[prev])){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }
        // ans.push_back(lastIndex);
        reverse(ans.begin(),ans.end());
        return ans;
    }
