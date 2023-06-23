#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
vector<list<int>> adj, radj;
void topsort(int n, vector<bool> &vis, stack<int> &s)
{
    if (vis[n])
    {
        return;
    }
    vis[n] = true;
    for (auto &r : adj[n])
    {
        if (!vis[r])
            topsort(r, vis, s);
    }
    s.push(n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    radj.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        radj[y].push_back(x);
        adj[x].push_back(y);
    }

    stack<int> s;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            topsort(i, vis, s);
        }
    }
    vector<ll> ans(n + 1);
    ans[1] = 1;
    while (!s.empty())
    {
        int cur = s.top();

        for (auto &r : radj[cur])
        {
            ans[cur] = (ans[cur] + ans[r]) % MOD;
        }

        s.pop();
    }

    cout << ans[n];
    return 0;
}