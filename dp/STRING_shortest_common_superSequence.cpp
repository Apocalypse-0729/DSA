class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        string final = "";
        while (i > 0 && j > 0) {
            if (s[i - 1] == t[j - 1]) {
                final = s[i - 1] + final;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                final = s[i - 1] + final;
                i--;
            } else {
                final = t[j - 1] + final;
                j--;
            }
        }
        while (i > 0) {
            final = s[i - 1] + final;
            i--;
        }
        while (j > 0) {
            final = t[j - 1] + final;
            j--;
        }
        return final;
    }
};
