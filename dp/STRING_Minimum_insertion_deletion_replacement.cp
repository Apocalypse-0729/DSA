class Solution {
public:
    int func(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=func(i-1,j-1,s,t,dp);
        return dp[i][j]=1+min(func(i-1,j-1,s,t,dp),min(func(i-1,j,s,t,dp),func(i,j-1,s,t,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return func(n-1,m-1,word1,word2,dp);
    }
};
