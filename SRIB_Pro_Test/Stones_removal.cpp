#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define forn(a, n, inc) for (int i = a; i <= n; i += inc)
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> one_n(n), two_n(n);
    forn(0, n - 1, 1)
    {
        cin >> one_n[i];
    }
    forn(0, n - 1, 1)
    {
        cin >> two_n[i];
    }
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = one_n[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + one_n[i], dp[i - 1][1]);
        dp[i][1] = min(dp[i - 1][0] + two_n[i], dp[i - 1][1] + one_n[i]);
    }
    cout << dp[n - 1][0] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
