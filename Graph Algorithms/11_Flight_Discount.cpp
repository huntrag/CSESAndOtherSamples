#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
#define INF INT64_MAX

vector<ll> dijkshtra(int src, vector<vector<pair<ll, ll>>> edges, vector<bool> vis)
{
    int n = vis.size() - 1;
    priority_queue<pair<ll, int>> pq;
    vector<ll> dis(n + 1, INF);
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        pair<ll, int> node = pq.top();
        pq.pop();
        if (vis[node.se])
        {
            continue;
        }
        vis[node.se] = true;
        for (auto &r : edges[node.se])
        {
            if (vis[r.fi])
            {
                continue;
            }
            if (dis[r.fi] == INF || dis[r.fi] > -node.fi + r.se)
            {
                dis[r.fi] = (ll)-node.fi + r.se;
                pq.push({-dis[r.fi], r.fi});
            }
        }
    }
    return dis;
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
    vector<vector<pair<ll, ll>>> edge(n + 1);
    vector<vector<pair<ll, ll>>> redge(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll l;
        cin >> x >> y >> l;
        edge[x].push_back({y, l});
        redge[y].push_back({x, l});
    }
    vector<bool> vis(n + 1, false);
    vector<ll> dis = dijkshtra(1, edge, vis);
    vector<ll> rdis = dijkshtra(n, redge, vis);

    ll ans = INF, j;
    for (int i = 1; i <= n; i++)
    {
        for (auto &r : edge[i])
        {
            j = r.fi;
            if (dis[i] == INF || rdis[j] == INF)
            {
                continue;
            }
            ans = (ll)min((ll)ans, (ll)dis[i] + r.se / 2 + rdis[j]);
        }
    }
    cout << ans;

    return 0;
}