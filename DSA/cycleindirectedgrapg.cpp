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
    vvi adj;

    Graph(int n)
    {
        this->n = n;
        // 0 indexed vertices
        this->adj.resize(n);
    }

    void add(int x, int y)
    {
        // x--> y
        adj[x].push_back(y);
    }

    bool isCycle()
    {
        vector<bool> rec(n + 1, false);
        vector<bool> vis(n + 1, false);
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            ans = ans | dfs(i, rec, vis);
        }

        return ans;
    }

    bool dfs(int v, vector<bool> &rec, vector<bool> &vis)
    {
        if (rec[v])
        {
            return true;
        }
        if (vis[v])
        {
            return false;
        }

        bool ans = false;
        rec[v] = true;
        for (auto &r : adj[v])
        {
            ans = ans | dfs(r, rec, vis);
        }
        rec[v] = false;
        vis[v] = true;

        return ans;
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
        Graph *g = new Graph(6);
        g->add(1, 2);
        g->add(3, 4);
        g->add(4, 5);
        g->add(5, 3);

        cout << g->isCycle();
    }
    return 0;
}