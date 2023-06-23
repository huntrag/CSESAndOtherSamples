#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

struct col
{
    ll fi;
    ll se;

    bool operator()(col a, col b)
    {
        if (a.fi > b.fi)
        {
            return true;
        }
        else if (a.fi == b.fi)
        {
            return a.se > b.se;
        }
        else
            return false;
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
    int n, m, x, y, l;
    cin >> n >> m;
    list<col> *edge;
    edge = new list<col>[n + 1];
    while (m--)
    {
        cin >> x >> y >> l;
        edge[x].push_back({y, l});
    }
    vector<ll> dis(n + 1, -1);
    dis[1] = 0;
    priority_queue<col, vector<col>, col> pq;
    vector<bool> vis(n + 1);
    vis[1] = true;
    pq.push({0, 1});
    dis[1] = 0;
    while (!pq.empty())
    {
        int vert = pq.top().se;
        int dist = pq.top().fi;
        vis[vert] = true;
        pq.pop();
        for (auto &r : edge[vert])
        {
            if (!vis[r.fi] && ((dis[r.fi] > dist + r.se) || dis[r.fi] == -1))
            {
                dis[r.fi] = dist + r.se;
                pq.push({dis[r.fi], r.fi});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}