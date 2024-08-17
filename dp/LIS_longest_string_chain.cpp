class Solution {
public:
    bool valid(string &s2, string &s1){
        if(s1.size() - s2.size() != 1)
            return false;
        int i = 0, j = 0;
        while(j != s2.size()){
            if(i == s1.size())
                return false;
            if(s1[i] == s2[j])
                i++, j++;
            else
                i++;
        }
        return true;
    }
    static bool cmp(string &a, string &b){
        return (a.length()<b.length());
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        // for(auto it:words) cout<<it<<" ";
        // cout<<endl;
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(valid(words[prev],words[i]) && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};
