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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> prefix(n + 1);
    prefix[0] = 0;
    prefix[1] = a[0];
    for (ll i = 2; i <= n; i++)
    {
        prefix[i] = a[i - 1] + prefix[i - 1];
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = a[i];
    }

    for (ll st = 1; st < n; st++)
    {
        ll j = st;
        ll i = 0;
        for (; j < n; j++)
        {
            dp[i][j] = max(a[i] + (prefix[j + 1] - prefix[i + 1]) - dp[i + 1][j],
                           a[j] + (prefix[j] - prefix[i]) - dp[i][j - 1]);
            i++;
        }
    }

    cout << dp[0][n - 1];
    return 0;
}