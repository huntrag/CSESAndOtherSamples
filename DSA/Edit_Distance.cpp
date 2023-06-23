#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // cout << setw(2) << "'";

    for (int j = 1; j <= m; j++)
    {
        // cout << setw(2) << word2[j - 1];
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    // cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        // cout << setw(2) << word1[i - 1];
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            // cout << setw(2) << dp[i][j];
        }
        // cout << "\n";
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
        string s, r;
        getline(cin >> ws, s);
        getline(cin >> ws, r);

        cout << minDistance(s, r);
    }
    return 0;
}