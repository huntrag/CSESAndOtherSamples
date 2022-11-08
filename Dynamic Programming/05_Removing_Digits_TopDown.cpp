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
    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp > 0)
        {
            dp[i] = min(dp[i], dp[i - (temp % 10)] + 1);
            temp /= 10;
        }
    }
    cout << dp[n];
    return 0;
}