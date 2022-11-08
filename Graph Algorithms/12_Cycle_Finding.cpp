#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
#define INF INT_MAX
typedef struct
{
    int src;
    int des;
    ll val;
} node;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, j;
    cin >> n >> m;
    vector<node> edge(m);
    for (j = 0; j < m; j++)
    {
        int x, y;
        ll l;
        cin >> x >> y >> l;
        edge[j].src = x;
        edge[j].des = y;
        edge[j].val = l;
    }
    vector<ll> dis(n + 1);
    vector<int> parent(n + 1, -1);
    int x;
    for (int i = 1; i <= n; i++)
    {
        x = -1;
        for (auto &e : edge)
        {
            if (dis[e.des] > dis[e.src] + e.val)
            {
                dis[e.des] = dis[e.src] + e.val;
                parent[e.des] = e.src;
                x = e.des;
            }
        }
    }

    if (x == -1)
    {
        cout << "NO\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            x = parent[x];
        }
        stack<int> cycle;
        for (int v = x;; v = parent[v])
        {
            cycle.push(v);
            if (v == x and cycle.size() > 1)
            {
                break;
            }
        }
        cout << "YES\n";
        while (!cycle.empty())
        {
            cout << cycle.top() << " ";
            cycle.pop();
        }
    }

    return 0;
}