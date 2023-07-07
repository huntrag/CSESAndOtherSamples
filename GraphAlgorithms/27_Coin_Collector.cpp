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
    int cnt;
    vector<vector<int>> adj;
    vector<vector<int>> rev;
    vector<int> order;
    vector<bool> vis;
    vector<int> order1;
    vector<ll> comp;
    unordered_map<ll, ll> sums;
    vll a;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        rev.resize(n + 1);
        vis.resize(n + 1);
        comp.resize(n + 1);
    }

    void add(int src, int des)
    {
        adj[src].push_back(des);
        rev[des].push_back(src);
    }

    void dfs1(int v)
    {
        vis[v] = true;
        for (auto &r : adj[v])
        {
            if (!vis[r])
                dfs1(r);
        }
        order.push_back(v);
    }

    void dfs2(int v, vi &comp)
    {
        vis[v] = true;
        comp.push_back(v);
        for (auto &r : rev[v])
        {
            if (!vis[r])
                dfs2(r, comp);
        }
    }

    int strong()
    {
        fill(vis.begin(), vis.end(), false);
        int tmr = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs1(i);
        }

        reverse(order.begin(), order.end());
        fill(vis.begin(), vis.end(), false);
        int count = 0;
        for (int i = 0; i < order.size(); i++)
        {
            if (!vis[order[i]])
            {
                vector<int> ans;
                dfs2(order[i], ans);
                ll sum = 0;
                for (int j = 0; j < ans.size(); j++)
                {
                    comp[ans[j]] = count;
                    sum = (ll)sum + a[ans[j]];
                }
                sums[count] = sum;
                count++;
            }
        }
        return count;
    }

    vector<set<int>> create()
    {
        this->cnt = strong();
        vector<set<int>> dadj(cnt + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (comp[i] != comp[adj[i][j]])
                {
                    dadj[comp[i]].insert(comp[adj[i][j]]);
                }
            }
        }
        return dadj;
    }

    ll dfs3(int v, vector<set<int>> &dadj, vll &dp)
    {
        if (dp[v])
            return dp[v];
        dp[v] = sums[v];

        for (auto &r : dadj[v])
        {
            dp[v] = max(dp[v], dfs3(r, dadj, dp) + sums[v]);
        }
        return dp[v];
    }

    void top(int v, vector<set<int>> &a)
    {
        vis[v] = true;
        for (auto &r : a[v])
        {
            if (!vis[r])
                top(r, a);
        }
        order1.push_back(v);
    }

    ll ans()
    {
        vector<set<int>> dadj = create();
        vis.resize(cnt + 1);
        ll mx = 0;
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < cnt; i++)
        {
            if (!vis[i])
            {
                top(i, dadj);
            }
        }

        reverse(order1.begin(), order1.end());
        vector<ll> dp(cnt, 0);

        for (int i = 0; i < cnt; i++)
        {
            ll sdf = dfs3(order1[i], dadj, dp);
            mx = max(mx, sdf);
        }
        return mx;
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
    // cin>>test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vll a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        Graph *g = new Graph(n);
        g->a = a;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            g->add(x, y);
        }
        cout << g->ans();
    }
    return 0;
}