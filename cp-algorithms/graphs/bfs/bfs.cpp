#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int n, m;
vector<vector<int>> adj;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    // n be number of vertices and m be number of edges
    cin >> n >> m;
    // if n is 0 indexed then do n=n+1
    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // BFS with putting in distances and parents

    queue<int> q;
    vector<bool> vis(n);
    vector<int> dis(n), parent(n);

    int src = 0;

    q.push(src);
    parent[src] = -1;
    dis[src] = 0;
    vis[src] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &neigh : adj[cur])
        {
            if (!vis[neigh])
            {
                vis[neigh] = true;
                q.push(neigh);
                dis[neigh] = dis[cur] + 1;
                parent[neigh] = cur;
            }
        }
    }

    // ----------------------------------------------------

    // In order to trace back the path
    int des;

    if (!vis[des])
    {
        cout << "No path!";
    }
    else
    {
        vector<int> path;
        for (int prev = des; prev != src; prev = parent[prev])
        {
            path.push_back(prev);
        }
        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << i << " ";
        }
    }

    return 0;
}