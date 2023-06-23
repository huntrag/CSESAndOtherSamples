#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef pair<int, int> pii;
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
    vector<int> comp;
    vector<list<int>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<bool> vis(n + 1);
    vis[0] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            comp.push_back(i);
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto &r : v[cur])
                {
                    if (!vis[r])
                    {
                        vis[r] = true;
                        q.push(r);
                    }
                }
            }
        }
    }
    int sz = comp.size();
    cout << sz - 1 << "\n";
    if (sz == 1)
    {
        return 0;
    }
    cout << comp[0] << " " << comp[sz - 1] << "\n";
    for (int i = 0; i < sz - 2; i++)
    {
        cout << comp[i] << " " << comp[i + 1] << "\n";
    }
    return 0;
}