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
    int n;
    cin >> n;
    int ans = n * (n + 1) / 2;
    if (ans % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    ans = ans / 2;
    vector<ll> dp(ans + 1);
    vector<ll> prev(ans + 1);
    prev[0] = 1l;
    dp[0] = 1l;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= ans; j++)
        {
            if (j - i >= 0)
            {
                dp[j] = (ll)(prev[j] + prev[j - i]) % MOD;
            }
        }
        for (int j = 1; j <= ans; j++)
        {
            prev[j] = (ll)dp[j];
        }
    }
    cout << (ll)((dp[ans]) * (500000004)) % MOD;
    return 0;
}