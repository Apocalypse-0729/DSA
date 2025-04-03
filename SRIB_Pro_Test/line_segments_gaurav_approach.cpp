#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) {
  if (a[1] != b[1])
    return a[1] < b[1];
  return a[0] < b[0];
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

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;

  vector<vector<int>> x, y, p;
  for (int i = 0; i < n - 1; i++) {
    if (v[i].first == v[i + 1].first) {
      if (v[i].second < v[i + 1].second)
        x.push_back({v[i].first, v[i].second, v[i + 1].second});
      else
        x.push_back({v[i].first, v[i + 1].second, v[i].second});
    } else {
      if (v[i].first < v[i + 1].first)
        y.push_back({v[i].second, v[i].first, v[i + 1].first});
      else
        y.push_back({v[i].second, v[i + 1].first, v[i].first});
    }
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    p.push_back({a, b, i});
  }
  sort(p.begin(), p.end());

  // for (auto vec : x)
  //   cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
  // for (auto vec : y)
  //   cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
  // for (auto vec : p)
  //   cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;

  int j = 0;
  unordered_set<int> ans;
  for (int i = 0; i < x.size(); i++) {
    int line_x = x[i][0];
    while (j < m && p[j][0] < line_x)
      j++;
    if (j == m)
      break;
    while (j < m && p[j][1] < x[i][1])
      j++;
    if (j == m)
      break;
    if (line_x == p[j][0] && p[j][1] >= x[i][1] && p[j][1] <= x[i][2])
      ans.insert(p[j++][2]);
    if (j == m)
      break;
  }

  sort(p.begin(), p.end(), cmp);
  j = 0;
  for (int i = 0; i < n - 1; i++) {
    int line_y = y[i][0];
    while (j < m && p[j][1] < line_y)
      j++;
    if (j == m)
      break;
    while (j < m && p[j][0] < y[i][1])
      j++;
    if (j == m)
      break;
    if (line_y == p[j][1] && p[j][0] >= y[i][1] && p[j][0] <= y[i][2])
      ans.insert(p[j++][2]);
    if (j == m)
      break;
  }
  cout << ans.size() << endl;

  return 0;
}
