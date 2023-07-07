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
    int m;
    vector<vector<int>> adj;
    vector<vector<int>> rev;
    vector<int> order;
    vector<bool> vis;
    vector<int> comp;

    Graph(int n)
    {
        this->n = n;
        this->m = n / 2;
        // first m are + and next m are -
        adj.resize(n + 1);
        rev.resize(n + 1);
        comp.resize(n + 1);
        vis.resize(n + 1);
    }

    int flip(int x)
    {
        if (x > m)
        {
            return x - m;
        }
        else
        {
            return x + m;
        }
    }

    void add(int src, int des)
    {
        adj[src].push_back(des);
        rev[des].push_back(src);
    }

    void add1(int x, int y)
    {
        // x v y
        add(flip(x), y);
        // cout << flip(x) << " " << y << "\n";
        add(flip(y), x);
        // cout << flip(y) << " " << x << "\n";
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

    void strong()
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
        for (int i = 0; i < order.size(); i++)
        {
            if (!vis[order[i]])
            {
                vector<int> ans;
                dfs2(order[i], ans);
                reverse(ans.begin(), ans.end());

                for (int j = 0; j < ans.size(); j++)
                {
                    comp[ans[j]] = i;
                }
            }
        }

        vector<char> ret(m + 1);
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << " " << comp[i] << "\n";
        // }

        for (int i = 1; i <= m; i++)
        {
            int j = flip(i);
            if (comp[i] == comp[j])
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
            else if (comp[i] > comp[j])
            {
                ret[i] = '+';
            }
            else
            {
                ret[i] = '-';
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << ret[i] << " ";
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
    // cin>>test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        Graph *g = new Graph(2 * m);
        for (int i = 1; i <= n; i++)
        {
            char c1, c2;
            int x1, x2;
            cin >> c1 >> x1 >> c2 >> x2;
            if (c1 == '-')
            {
                x1 = g->flip(x1);
            }
            if (c2 == '-')
            {
                x2 = g->flip(x2);
            }

            g->add1(x1, x2);
        }
        // cout << "----------------------\n";
        g->strong();
    }
    return 0;
}