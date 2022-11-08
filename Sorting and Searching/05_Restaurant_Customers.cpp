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
        return a.first < b.first;
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
    vector<pair<int, int>> a(2 * n, {0, 0});
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        a[j++] = mp(v[i].first, 1);
        a[j++] = mp(v[i].se, -1);
    }
    sort(a.begin(), a.end());
    int mx = 0, count = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        count += a[i].second;
        mx = max(mx, count);
    }
    cout << mx;
    return 0;
}