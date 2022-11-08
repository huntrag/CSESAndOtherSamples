//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define INF LLONG_MAX
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q, x, y, l;
    cin >> n >> m >> q;
    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));
    while (m--)
    {
        cin >> x >> y >> l;
        dis[x][y] = min((ll)dis[x][y], (ll)l);
        dis[y][x] = dis[x][y];
    }
    for (int i = 0; i < n + 1; i++)
    {
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (dis[i][j] > (dis[i][k] + dis[k][j]) && (dis[k][j] != INF && dis[i][k] != INF))
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
            }
        }
    }
    while (q--)
    {
        cin >> x >> y;
        if (dis[x][y] == INF)
        {
            cout << -1 << "\n";
        }
        else
            cout << dis[x][y] << "\n";
    }
    return 0;
}