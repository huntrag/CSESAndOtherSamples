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
    ll n;
    vector<vector<pair<ll, ll>>> adj;

    Graph(ll n)
    {
        this->n = n;
        adj.resize(n + 1);
    }

    void add(ll u, ll v, ll w)
    {
        adj[u].push_back(make_pair(v, w));
    }

    void dijkstra()
    {
        using pii = pair<ll, ll>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<ll> dis(n + 1, LLONG_MAX);
        unordered_map<ll, ll> count(n + 1);
        unordered_map<ll, ll> mx(n + 1);
        unordered_map<ll, ll> mn(n + 1);
        count[1] = 1;
        pq.push({dis[1] = 0, 1});

        while (!pq.empty())
        {
            ll v = pq.top().second;
            ll d_v = pq.top().first;
            pq.pop();

            if (d_v != dis[v])
            {
                continue;
            }

            for (auto &neigh : adj[v])
            {
                ll cost = neigh.se;
                ll nxt = neigh.fi;
                ll alt = cost + d_v;

                if (alt == dis[nxt])
                {
                    count[nxt] = (count[v] + count[nxt]) % MOD;
                    mn[nxt] = min(mn[nxt], mn[v] + 1);
                    mx[nxt] = max(mx[nxt], mx[v] + 1);
                }
                else if (alt < dis[nxt])
                {
                    count[nxt] = (count[v]) % MOD;
                    mn[nxt] = mn[v] + 1;
                    mx[nxt] = mx[v] + 1;
                    pq.push(make_pair(dis[nxt] = alt, nxt));
                }
            }
        }
        cout << dis[n] << " " << count[n] << " " << mn[n] << " " << mx[n];
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
            ll u, v, w;
            cin >> u >> v >> w;
            g->add(u, v, w);
        }

        g->dijkstra();
    }
    return 0;
}