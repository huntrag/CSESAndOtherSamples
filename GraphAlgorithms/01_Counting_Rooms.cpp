#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

void dfs(vector<vector<bool>> &vis, int i, int j)
{
    int n = vis.size(), m = vis[0].size();
    if (i < 0 || i > n - 1 || j < 0 || j > m - 1 || vis[i][j])
    {
        return;
    }
    vis[i][j] = true;
    dfs(vis, i + 1, j);
    dfs(vis, i, j + 1);
    dfs(vis, i - 1, j);
    dfs(vis, i, j - 1);
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
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                vis[i][j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(vis, i, j);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}