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
    string s, r;
    getline(cin >> ws, s);
    getline(cin >> ws, r);
    vector<vector<int>> dp(s.length() + 1, vector<int>(r.length() + 1, 0));
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= r.length(); i++)
    {
        dp[0][i] = i;
    }
    vector<int> sfreq(26, 0);
    for (int i = 1; i <= s.length(); i++)
    {
        sfreq[s[i - 1] - 'A']++;
        vector<int> rfreq(26, 0);
        for (int j = 1; j <= r.length(); j++)
        {
            rfreq[r[j - 1] - 'A']++;
            if ((s[i - 1] == r[j - 1]))
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int x = min(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] = min(x, dp[i - 1][j - 1]) + 1;
            }
        }
    }
    cout << dp[s.length()][r.length()];
    return 0;
}