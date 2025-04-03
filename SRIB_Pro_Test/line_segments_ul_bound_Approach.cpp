
// / Sarthak stalk krna buri baat hoti hai
#include <iostream>      // for input and output streams
#include <vector>        // for std::vector
#include <algorithm>     // for algorithms like sort, max, min
#include <string>        // for std::string
#include <map>           // for std::map
#include <unordered_map> // for std::unordered_map
#include <set>           // for std::set
#include <unordered_set> // for std::unordered_set
#include <queue>         // for std::queue, std::priority_queue
#include <stack>         // for std::stack
#include <deque>         // for std::deque
#include <list>          // for std::list
#include <iterator>      // for std::iterators
#include <functional>    // for std::function, std::bind
#include <numeric>       // for numeric algorithms like accumulate
#include <cmath>         // for mathematical functions like sqrt, pow
#include <limits>        // for limits of data types
#include <iomanip>       // for std::setprecision, std::fixed
#include <fstream>       // for file I/O
#include <sstream>       // for string streams
#include <bitset>        // for bitset operations
#include <tuple>         // for std::tuple
#include <utility>       // for std::pair, std::move, std::forward
#include <ctime>         // for std::time
#include <chrono>        // for time utilities
#include <cassert>       // for assertions
#include <random>        // for random number generation
#include <memory>        // for smart pointers
using namespace std;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for (auto &i : v)
        cin >> i.first >> i.second;
    vector<pair<ll, ll>> pts(m);
    for (auto &i : pts)
        cin >> i.first >> i.second;
    map<ll, vector<ll>> abscissa, ordinate;
    for (auto &i : pts)
    {
        abscissa[i.first].push_back(i.second);
        ordinate[i.second].push_back(i.first);
    }
    set<pair<ll, ll>> st;
    for (ll i = 1; i < n - 1; i++)
    {
        st.insert(v[i]);
    }
    for (auto &i : abscissa)
    {
        sort(i.second.begin(), i.second.end());
    }
    for (auto &i : ordinate)
    {
        sort(i.second.begin(), i.second.end());
    }
    set<pair<ll, ll>> res;
    for (ll i = 0; i < n - 1; i++)
    {
        pair<ll, ll> st = v[i];
        pair<ll, ll> ed = v[i + 1];
        if (v[i].first == v[i + 1].first)
        {
            ll lg = max(st.second, ed.second);
            ll sm = min(st.second, ed.second);
            ll ulim = upper_bound(abscissa[v[i].first].begin(), abscissa[v[i].first].end(), lg) - abscissa[v[i].first].begin() - 1;
            ll llim = lower_bound(abscissa[v[i].first].begin(), abscissa[v[i].first].end(), sm) - abscissa[v[i].first].begin();
            for (ll it = llim; it <= ulim; it++)
            {
                res.insert({v[i].first, abscissa[v[i].first][it]});
            }
        }
        else
        {
            ll lg = max(ed.first, st.first);
            ll sm = min(ed.first, st.first);
            ll ulim = upper_bound(ordinate[v[i].second].begin(), ordinate[v[i].second].end(), lg) - ordinate[v[i].second].begin() - 1;
            ll llim = lower_bound(ordinate[v[i].second].begin(), ordinate[v[i].second].end(), sm) - ordinate[v[i].second].begin();
            for (ll it = llim; it <= ulim; it++)
            {
                res.insert({ordinate[v[i].second][it], v[i].second});
            }
        }
    }
    cout << res.size() << "\n";
}
