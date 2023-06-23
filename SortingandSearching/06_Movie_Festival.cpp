#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define mp(x, y) make_pair(x, y)
#define MOD 1e9 + 7
#define fi first
#define se second

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = mp(x, y);
    }
    sort(v.begin(), v.end(), comp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i].fi << " " << v[i].se << "\n";
    // }
    int count = 1;
    int mx = v[0].se;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first >= mx)
        {
            mx = max(mx, v[i].second);
            count++;
        }
    }
    cout << count;
    return 0;
}