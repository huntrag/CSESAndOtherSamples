
// Dynamic programming solution:
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int long long
#define pii pair<int, int>
#define fi first
#define sc second
const int li = 2e5 + 10,
          inf = 2e9;

int n, m, dp[li], par[li], vis[li];
vector<int> adj[li];

void dfs(int s)
{
    vis[s] = true;
    for (auto u : adj[s])
    {
        if (!vis[u])
            dfs(u);
        if (dp[s] < dp[u] + 1 && dp[u] != -inf)
        {
            dp[s] = dp[u] + 1;
            par[s] = u;
        }
    }
}

void try_all()
{
    par[n] = -1;
    for (int i = 1; i < n; i++)
        dp[i] = -inf;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    try_all();

    if (dp[1] == -inf)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> ans;
    int now = 1;

    while (now != -1)
    {
        ans.push_back(now);
        now = par[now];
    }

    cout << ans.size() << "\n";
    for (auto u : ans)
        cout << u << " ";
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}