int fun(int ind, int last, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(ind==0){
            int maxi=0;
            for(int i=0; i<3; i++){
                if(i!=last){
                    maxi=max(maxi,arr[0][i]);
                }
            }
            return maxi;
        }
        if(dp[ind][last]!=-1) return dp[ind][last];
        
        int maxi=0;
        for(int i=0; i<3; i++){
            if(i!=last){
                maxi=max(maxi,arr[ind][i]+fun(ind-1,i,arr,dp));
            }
        }
        return dp[ind][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return fun(n-1,3,arr,dp);
    }
