#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
int main() {
  if (!freopen("input.txt", "r", stdin)) {
    perror("Error opening input file");
    return 1;
  }
  if (!freopen("output.txt", "w", stdout)) {
    perror("Error opening output file");
    return 1;
  }
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vector<vvi> dp(n, vvi(9, vector<int>(9, 0)));
  for (int i = 0; i < n; i++) {

    if (i != 0)
      dp[i] = dp[i - 1];
    int s_0 = v[i][0] - '1', s_n = v[i].back() - '1';
    dp[i][s_0][s_n] =
        max(((i != 0) ? dp[i - 1][s_0][s_n] : 0), (int)v[i].size());
    for (int j = 0; j < 9; j++)
      dp[i][j][s_n] =
          max(((i != 0) ? dp[i - 1][j][s_n] : 0),
              int(((i != 0) ? dp[i - 1][j][s_0] : 0) + v[i].length()));
  }
  int ans = 0;
  for (int i = 0; i < 9; i++)
    ans = max(ans, dp[n - 1][i][i]);
  cout << ans << endl;
  return 0;
}
