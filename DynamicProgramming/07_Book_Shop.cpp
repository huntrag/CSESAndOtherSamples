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
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    vector<int> dp(k + 1, 0);
    vector<int> prev(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[j] = max(prev[j], dp[j - 1]);
            if (j - price[i] >= 0)
            {
                dp[j] = max(dp[j], prev[j - price[i]] + pages[i]);
            }
        }
        for (int j = 1; j <= k; j++)
        {
            prev[j] = dp[j];
        }
    }
    cout << dp[k];
    return 0;
}