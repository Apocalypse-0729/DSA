class Solution {
public:
    int func(int i, int j, string &s,string &t, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=func(i-1,j-1,s,t,dp)+func(i-1,j,s,t,dp);
        return dp[i][j]=func(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        // make the first column will all values 1 and apply tabulation
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return func(n-1,m-1,s,t,dp);
    }
};
