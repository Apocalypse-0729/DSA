class Solution {
  public:
  const int mod=1e9+7;
    int func(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(i==0){
            if(sum==0 && arr[0]==0)return 2;
            if(sum==0 || sum==arr[0]) return 1;
            return 0;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notake=func(i-1,sum,arr,dp);
        int take=0;
        if(arr[i]<=sum){
            take=func(i-1,sum-arr[i],arr,dp);
        }
        return dp[i][sum]=(take+notake)%(mod);
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totSum=0;
        for(auto it:arr) totSum+=it;
        if(totSum-d<0) return 0;
        if((totSum-d)%2==1) return 0;
        int sum=(totSum-d)/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return func(n-1,sum,arr,dp);
    }
};
