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

class Tree
{
public:
    int n;
    vvi adj;
    vpii dis;
    vpii ans;

    Tree(int x)
    {
        n = x;
        adj.resize(n);
        dis.resize(n);
        ans.resize(n);
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int maxdis(int v, int parent)
    {
        if (dis[v].first == 1)
        {
            return dis[v].second;
        }
        int mx = 0;
        for (auto &r : adj[v])
        {
            if (r == parent)
            {
                continue;
            }
            mx = max(mx, maxdis(r, v));
        }
        dis[v] = make_pair(1, mx + 1);
        return dis[v].second;
    }

    void solve(int v, int parent, int othermx)
    {
        if (ans[v].first == 1)
        {
            return;
        }
        int mx_ind = -1, mx = -1;
        for (auto &r : adj[v])
        {
            if (r == parent)
            {
                continue;
            }
            if (dis[r].second > mx)
            {
                mx_ind = r;
                mx = dis[r].second;
            }
        }
        if (mx == -1)
        {
            ans[v] = make_pair(1, othermx + 1);
            return;
        }
        int smx = -1;
        for (auto &r : adj[v])
        {
            if (r == parent || r == mx_ind)
            {
                continue;
            }
            smx = max(smx, dis[r].second);
        }

        if (smx == -1)
        {
            solve(mx_ind, v, othermx + 1);
            ans[v] = make_pair(1, max(othermx + 1, dis[v].second));
            return;
        }

        // found out maxes and second maxes

        for (auto &r : adj[v])
        {
            if (r == parent)
            {
                continue;
            }
            if (r == mx_ind)
            {
                solve(r, v, max(smx + 1, othermx + 1));
                continue;
            }
            solve(r, v, max(mx + 1, othermx + 1));
        }

        ans[v] = make_pair(1, max(othermx + 1, dis[v].second));
    }

    void really()
    {
        maxdis(0, -1);
        solve(0, -1, 0);
    }

    int get(int i)
    {
        return ans[i].second - 1;
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
        Tree t(n);

        int x, y;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            t.add(x, y);
        }
        t.really();
        for (int i = 0; i < n; i++)
        {
            cout << t.get(i) << " ";
        }
    }
    return 0;
}