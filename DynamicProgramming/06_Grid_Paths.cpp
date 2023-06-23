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
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin >> ws, s);
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '*')
            {
                dp[i][j] = -1;
            }
        }
    }
    if (dp[0][0] == -1 || dp[n - 1][n - 1])
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n && dp[i][0] != -1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n && dp[0][i] != -1; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] != -1)
            {
                dp[i][j] = ((dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]) + (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1])) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}