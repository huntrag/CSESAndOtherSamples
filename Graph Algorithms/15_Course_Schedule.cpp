#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

class Graph
{
    int n;
    list<int> *adj;

public:
    Graph(int n)
    {
        this->n = n;
        this->adj = new list<int>[n + 1];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool dfs(int node, vector<bool> &vis, vector<bool> &flag)
    {
        vis[node] = true;
        flag[node] = true;
        for (auto &r : adj[node])
        {
            if (!vis[r])
            {
                if (dfs(r, vis, flag))
                {
                    return true;
                }
            }
            if (flag[r])
            {
                return true;
            }
        }

        flag[node] = false;
        return false;
    }

    bool checkCycle()
    {
        vector<bool> vis(n + 1);
        vector<bool> resflag(n + 1);
        bool ans = false;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, resflag))
                {
                    ans = true;
                    break;
                }
            }
        }
        return ans;
    }

    void topSortUtil(int node, vector<bool> &vis, stack<int> &stk)
    {
        vis[node] = true;

        for (auto &r : adj[node])
        {
            if (!vis[r])
            {
                topSortUtil(r, vis, stk);
            }
        }
        stk.push(node);
    }

    void topSort()
    {
        if (checkCycle())
        {
            cout << "IMPOSSIBLE";
            return;
        }
        vector<bool> vis(n + 1);
        stack<int> stk;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                topSortUtil(i, vis, stk);
            }
        }

        while (!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }
    }
};

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
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.topSort();
    return 0;
}