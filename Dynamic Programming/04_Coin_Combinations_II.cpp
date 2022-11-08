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
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j - coins[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
            }
        }
    }
    cout << dp[k];
    return 0;
}