#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y;
    cin >> n >> m;
    vector<list<int>> edge(n + 1);
    while (m--)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    vector<bool> colors(n + 1, 0);
    vector<bool> vis(n + 1, false);
    bool alert = false;
    for (int i = 1; i <= n && !alert; i++)
    {
        if (vis[i])
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        colors[i] = 0;
        vis[i] = true;
        while (!q.empty() && !alert)
        {
            int cur = q.front();
            q.pop();
            for (auto &r : edge[cur])
            {
                if (!vis[r])
                {
                    colors[r] = colors[cur] ^ 1;
                    vis[r] = true;
                    q.push(r);
                }
                else
                {
                    if (colors[r] ^ colors[cur] != 1)
                    {
                        alert = true;
                    }
                }
            }
        }
    }
    if (alert)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << colors[i] + 1 << " ";
    }
    return 0;
}