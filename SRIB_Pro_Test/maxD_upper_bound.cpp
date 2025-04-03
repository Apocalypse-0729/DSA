#include <bits/stdc++.h>
using namespace std;

int maxDiffD(const vector<int>& a, const vector<int>& b) {
    vector<int> sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    set<int> s;
    for (int x : sa) s.insert(x);
    for (int x : sb) s.insert(x);

    vector<int> c;
    c.push_back(*s.begin() - 1);
    for (int x : s) c.push_back(x);
    c.push_back(*s.rbegin() + 1);

    int mx = INT_MIN, bestD = 0;
    
    for (int d : c) {
        int ca = upper_bound(sa.begin(), sa.end(), d) - sa.begin();
        int cb = upper_bound(sb.begin(), sb.end(), d) - sb.begin();

        int as = ca + (sa.size() - ca) * 2;
        int bs = cb + (sb.size() - cb) * 2;

        int diff = as - bs;
        if (diff > mx) {
            mx = diff;
            bestD = d;
        }
    }

    return bestD;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {6, 7, 8, 9, 10};

    cout << "Optimal D: " << maxDiffD(a, b) << endl;
    return 0;
}
