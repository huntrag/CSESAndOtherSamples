#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int n, m;

vvi moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void solve(int ip, int jp, vvll &dp, vvb &vis, vvi &a)
{
    if (ip < 0 || ip >= n || jp < 0 || jp >= m)
    {
        return;
    }
    for (auto &move : moves)
    {
        int ni = ip + move[0];
        int nj = jp + move[1];

        if (ni < 0 || ni >= n || nj < 0 || nj >= m)
        {
            continue;
        }
        if (a[ip][jp] > a[ni][nj])
        {
            if (vis[ni][nj])
            {
                dp[ip][jp] = (dp[ip][jp] + (dp[ni][nj]) % MOD) % MOD;
            }
            else
            {
                solve(ni, nj, dp, vis, a);
                dp[ip][jp] = (dp[ip][jp] + (dp[ni][nj]) % MOD) % MOD;
            }
        }
    }
    vis[ip][jp] = true;
}

int countPaths(vector<vector<int>> &a)
{
    n = a.size();
    m = a[0].size();
    vvll dp(n, vll(m, 1));
    vvb vis(n, vector<bool>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false)
            {
                solve(i, j, dp, vis, a);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << dp[i][j] << " ";
            ans = (ans + dp[i][j]) % MOD;
        }
        // cout << "\n";
    }

    return (int)ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vvi a(n, vi(m));
        for (auto &r : a)
        {
            for (auto &c : r)
            {
                cin >> c;
            }
        }
        cout << countPaths(a);
    }
    return 0;
}