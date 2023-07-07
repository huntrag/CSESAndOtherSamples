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
    vector<vector<int>> adj;
    vector<vector<int>> rev;
    vector<int> order;
    vector<bool> vis;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        rev.resize(n + 1);
        vis.resize(n + 1);
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

    vvi strong()
    {
        fill(vis.begin(), vis.end(), false);
        int tmr = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                dfs1(i);
        }
        vvi ret;
        reverse(order.begin(), order.end());
        fill(vis.begin(), vis.end(), false);
        for (int i = 0; i < order.size(); i++)
        {
            if (!vis[order[i]])
            {
                vector<int> ans;
                dfs2(order[i], ans);
                reverse(ans.begin(), ans.end());
                ret.push_back(ans);
            }
        }

        for (int i = 0; i < ret.size(); i++)
        {
            for (int j = 0; j < ret[i].size(); j++)
            {
                cout << ret[i][j] << " ";
            }
            cout << "\n";
        }

        return ret;
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
            int x, y;
            cin >> x >> y;
            g->add(x, y);
        }
        g->strong();
    }
    return 0;
}