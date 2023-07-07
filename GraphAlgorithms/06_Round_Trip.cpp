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
public:
    int n;
    vector<vector<int>> adj;
    vector<int> color;
    vector<int> parent;

    Graph(int v)
    {
        this->n = v;
        adj.resize(v + 1);
        color.resize(v + 1);
        parent.resize(v + 1, -1);
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void printCycle()
    {
        vector<int> ans;
        bool res = false;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] != 2)
            {
                res = res | isCycle(i, -1, ans);
            }
            if (res)
            {
                break;
            }
        }

        if (!res)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        cout << ans.size() << "\n";
        for (auto &x : ans)
        {
            cout << x << " ";
        }
    }

    bool isCycle(int v, int prev, vector<int> &ans)
    {
        if (color[v] == 2)
        {
            return false;
        }

        if (color[v] == 1)
        {
            int cur = prev;
            ans.push_back(cur);

            while (cur != v)
            {
                cur = parent[cur];
                ans.push_back(cur);
            }

            return true;
        }
        parent[v] = prev;
        color[v] = 1;
        bool res = false;
        for (auto &neigh : adj[v])
        {
            if (neigh == parent[v])
            {
                continue;
            }
            res = res | isCycle(neigh, v, ans);
        }

        color[v] = 2;
        return res;
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
    int n, m;
    cin >> n >> m;
    Graph *g = new Graph(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g->add(x, y);
    }
    g->printCycle();
    return 0;
}