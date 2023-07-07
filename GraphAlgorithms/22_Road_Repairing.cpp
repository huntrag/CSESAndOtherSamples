#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

class Graph
{
public:
    int n;
    vector<vector<pair<ll, ll>>> adj;
    vector<bool> vis;

    Graph(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
        vis.resize(n + 1);
    }

    void add(ll x, ll y, ll w)
    {
        adj[x].push_back(make_pair(y, w));
        adj[y].push_back(make_pair(x, w));
    }

    bool comp1()
    {
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (flag)
                {
                    return false;
                }
                flag = true;
                dfs(i);
            }
        }
        return true;
    }

    void dfs(int v)
    {
        vis[v] = true;
        for (auto &r : adj[v])
        {
            if (!vis[r.first])
            {
                dfs(r.first);
            }
        }
    }

    void mst()
    {
        if (!comp1())
        {
            cout << "IMPOSSIBLE";
            return;
        }
        vll dis(n + 1, LLONG_MAX);
        vector<bool> ismst(n + 1, false);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        pq.push(make_pair(0, 1));
        dis[1] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            if (ismst[u] == true)
            {
                continue;
            }
            ismst[u] = true;

            for (auto &r : adj[u])
            {
                ll v = r.first;
                ll w = r.second;
                if (ismst[v] == false && dis[v] > w)
                {
                    dis[v] = w;
                    // ismst[v] = true;
                    pq.push(make_pair(dis[v], v));
                }
            }
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == LLONG_MAX)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            // cout << i << " " << dis[i] << "\n";
            ans = (ll)ans + dis[i];
        }
        cout << ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        Graph *g = new Graph(n);
        while (m--)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            g->add(x, y, w);
        }
        g->mst();
    }
    return 0;
}