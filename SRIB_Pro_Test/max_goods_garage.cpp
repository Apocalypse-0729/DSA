#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
vector<int> bfs(pii &s, vector<vector<int>> &a, int c, map<pii, int> &w) {
  int n = a.size(), m = a[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  queue<vector<int>> q;
  q.push({s.first, s.second, 0});
  vis[s.first][s.second] = 1;
  vector<int> ans(c, -1);
  while (!q.empty()) {
    vector<int> cur = q.front();
    q.pop();
    int x = cur[0], y = cur[1], d = cur[2];
    if (a[x][y] == 3) {
      ans[m[{x, y}]] = d;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (a[nx][ny] != 1 && !vis[nx][ny]) {
        vis[nx][ny] = 1;
        q.push({nx, ny, d + 1});
      }
    }
  }
  return ans;
}
int main() {
  if (!freopen("input.txt", "r", stdin)) {
    perror("Error opening input file");
    return 1;
  }
  if (!freopen("output.txt", "w", stdout)) {
    perror("Error opening output file");
    return 1;
  }

  int h, w, c = 0;
  pair<int, int> sr, d;
  cin >> h >> w;
  map<pii, int> wh;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
      if (a[i][j] == 3)
        wh[{i, j}] = c++;
      if (a[i][j] == 2)
        sr = make_pair(i, j);
      if (a[i][j] == 4)
        d = make_pair(i, j);
    }
  }
  vector<int> d_g = bfs(sr, a, c, wh), d_a = bfs(d, a, c, wh);
  int cost, ans = 0;
  cin >> cost;
  for (int i = 0; i < c; i++) {
    if (d_g[i] == -1 || d_a[i] == -1)
      continue;
    if (d_g[i] + d_a[i] > cost)
      continue;
    ans = max(ans, (cost - d_g[i]) / d_a[i] - 1);
  }
  cout << ans << endl;
}
