#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
#define INF LLONG_MAX

struct data
{
    int src;
    int des;
    ll val;
};

void dfs(int node, vector<list<int>> redge, vector<bool> &vis, stack<int> &s)
{
    vis[node] = true;
    bool comp = false;
    for (auto &r : redge[node])
    {
        if (vis[r])
        {
            continue;
        }
        s.push(r);
        dfs(r, redge, vis, s);
    }
}

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
    vector<struct data> a(m);
    vector<list<int>> redge(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        ll l;
        cin >> x >> y >> l;
        redge[y].push_back(x);
        a[i].src = x;
        a[i].des = y;
        a[i].val = l;
    }
    vector<ll> dis(n + 1, INF);
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[a[j].src] != INF && (dis[a[j].des] == INF || dis[a[j].des] < (ll)dis[a[j].src] + a[j].val))
            {
                dis[a[j].des] = dis[a[j].src] + a[j].val;
            }
        }
    }
    vector<bool> check(n + 1, false);
    vector<bool> vis(n + 1, false);
    for (int j = 0; j < m; j++)
    {
        if (dis[a[j].src] != INF && (dis[a[j].des] == INF || dis[a[j].des] < (ll)dis[a[j].src] + a[j].val))
        {
            check[a[j].des] = true;
            dis[a[j].des] = dis[a[j].src] + a[j].val;
        }
    }
    // for (auto &r : s)
    // {
    //     cout << r << " ";
    // }
    // cout << "\n";
    stack<int> f;
    f.push(n);
    dfs(n, redge, vis, f);
    bool ans = false;
    while (!f.empty())
    {
        if (check[f.top()])
        {
            ans = true;
        }
        f.pop();
    }
    if (ans)
    {
        cout << -1;
        return 0;
    }
    cout << dis[n];
    return 0;
}