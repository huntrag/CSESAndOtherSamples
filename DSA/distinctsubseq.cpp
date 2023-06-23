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

ll numDistinct(string s, string t)
{
    ll n = s.length();
    ll m = t.length();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (ll j = 1; j <= m; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (ll)(dp[i - 1][j] + dp[i - 1][j - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
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
    // cin >> test;
    while (test--)
    {
        string s, t;
        getline(cin >> ws, s);
        getline(cin >> ws, t);
        cout << numDistinct(s, t);
    }
    return 0;
}