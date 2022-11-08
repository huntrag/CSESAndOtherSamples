#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

static int total = 0;
int mx;
int maxi = 0;
int mini = MOD;

void dfs(int n, vector<list<pair<int, int>>> &adj, int count, int cost, vector<bool> &vis)
{
    if (cost == mx)
    {
        count++;
        total = (total + 1) % MOD;
        mini = min(mini, count);
        maxi = max(maxi, count);
        return;
    }
    vis[n] = true;

    for (auto &r : adj[n])
    {
        if (vis[r.fi])
        {
            continue;
        }
        else
        {
            count++;
            dfs(r.fi, adj, count, cost + r.se, vis);
            count--;
        }
    }
    vis[n] = false;
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
    vector<list<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    vector<int> dis(n + 1, -1);
    dis[1] = 0;
    vector<bool> vis(n + 1);
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (vis[cur.se])
        {
            continue;
        }

        for (auto &r : adj[cur.se])
        {
            if (vis[cur.se])
            {
                continue;
            }
            if (dis[r.fi] == -1 || dis[r.fi] > dis[cur.se] + r.se)
            {
                dis[r.fi] = dis[cur.se] + r.se;
                pq.push({dis[r.fi], r.fi});
            }
        }
    }

    mx = dis[n];
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
    }
    dfs(1, adj, 0, 0, vis);
    cout << mx << " " << total << " " << mini - 1 << " " << maxi - 1 << "\n";

    return 0;
}