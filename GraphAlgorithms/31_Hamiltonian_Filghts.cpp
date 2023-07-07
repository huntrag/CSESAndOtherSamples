// Best prblems for bitmasking
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vvi adj(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[y].push_back(x);
        }
        int tot = (1 << n);
        vvll dp(tot, vll(n));
        vll msk(n);
        msk[0] = 1;
        for (int i = 1; i < n; i++)
        {
            msk[i] = msk[i - 1] * 2;
        }
        dp[0][0] = 1;
        for (int i = 0; i < tot; i++)
        {
            if ((i & (1 << 0)) == 0)
                continue;

            // Only consider the full subsets
            if ((i & (1 << (n - 1))) && i != ((1 << n) - 1))
                continue;
            for (int j = 0; j < n; j++)
            {
                if ((i & msk[j]))
                {
                    int wi = (i ^ msk[j]);
                    if (wi == 0)
                    {
                        dp[i][j] = 1;
                        continue;
                    }
                    for (auto &inc : adj[j])
                    {
                        dp[i][j] = (dp[i][j] + dp[wi][inc]) % MOD;
                    }
                }
            }
        }

        cout << dp[tot - 1][n - 1];
    }
    return 0;
}