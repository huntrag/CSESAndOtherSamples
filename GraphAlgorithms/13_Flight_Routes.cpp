#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
#define _init(a, k)                    \
    for (int i = 0; i < a.size(); i++) \
        a[i] = k;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll l;
        cin >> x >> y >> l;
        graph[x].push_back({y, l});
    }

    vector<int> count(n + 1);
    vector<ll> ans;
    _init(count, 0);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty() && count[n] < k)
    {
        pair<ll, int> cur = pq.top();
        pq.pop();
        count[cur.se]++;
        if (cur.se == n)
        {
            ans.push_back(cur.fi);
        }
        if (count[cur.se] <= k)
        {
            for (auto &r : graph[cur.se])
            {
                pq.push({cur.fi + r.se, r.fi});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}