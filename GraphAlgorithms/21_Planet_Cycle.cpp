#include <bits/stdc++.h>
// Strongly connected compnenents.
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
    vector<int> adj;
    vector<vector<int>> res;
    vector<int> order;
    vector<bool> vis;
    vector<int> cycle;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        res.resize(n + 1);
        vis.resize(n + 1);
        cycle.resize(n + 1, -1);
    }

    void add(int x, int y)
    {
        if (x == y)
        {
            cycle[x] = 1;
        }
        adj[x] = y;
        res[y].push_back(x);
    }

    void dfs1(int v)
    {
        vis[v] = true;
        if (!vis[adj[v]])
        {
            dfs1(adj[v]);
        }
        order.push_back(v);
    }

    void dfs2(int v, vector<int> &ans)
    {
        vis[v] = true;
        ans.push_back(v);
        for (auto &r : res[v])
        {
            if (!vis[r])
            {
                dfs2(r, ans);
            }
        }
    }

    void dfs3(int v)
    {
        vis[v] = true;
        if (cycle[adj[v]] == -1)
        {
            dfs3(adj[v]);
        }
        cycle[v] = cycle[adj[v]] + 1;
    }

    void strong()
    {
        fill(vis.begin(), vis.end(), false);
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs1(i);
            }
        }
        reverse(order.begin(), order.end());
        fill(vis.begin(), vis.end(), false);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            if (!vis[order[i]])
            {
                vector<int> ans;
                dfs2(order[i], ans);
                if (ans.size() > 1)
                {
                    for (int j = 0; j < ans.size(); j++)
                    {
                        cycle[ans[j]] = ans.size();
                    }
                }
                else if (cycle[ans[0]] == -1)
                {
                    stk.push(ans[0]);
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        while (!stk.empty())
        {
            if (!vis[stk.top()])
            {
                dfs3(stk.top());
            }
            stk.pop();
        }

        for (int i = 1; i <= n; i++)
        {
            cout << cycle[i] << " ";
        }
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
        int n;
        cin >> n;
        Graph *g = new Graph(n);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            g->add(i, x);
        }
        g->strong();
    }
    return 0;
}