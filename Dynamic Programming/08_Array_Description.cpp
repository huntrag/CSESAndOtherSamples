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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> dp(k + 2, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (ll j = 1; j <= k; j++)
            {
                dp[j][i] = 1;
            }
        }
        else
        {
            dp[a[i]][i] = 1;
        }
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if (dp[j][i] == 1)
            {
                dp[j][i] = (ll)((dp[j][i - 1]) % MOD + (dp[j - 1][i - 1]) % MOD + (dp[j + 1][i - 1]) % MOD) % MOD;
            }
        }
    }
    ll sum = 0;
    for (ll i = 1; i <= k; i++)
    {
        sum = (ll)(sum + dp[i][n - 1]) % MOD;
    }
    cout << sum;
    return 0;
}