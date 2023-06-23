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

bool isScramble(string s1, string s2)
{
    int n = s1.size();
    vector dp(n + 1, vector(n, vector<int>(n)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[1][i][j] = s1[i] == s2[j];
        }
    }
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i < n + 1 - length; i++)
        {
            for (int j = 0; j < n + 1 - length; j++)
            {
                for (int newLength = 1; newLength < length; newLength++)
                {
                    const vector<int> &dp1 = dp[newLength][i];
                    const vector<int> &dp2 = dp[length - newLength][i + newLength];
                    dp[length][i][j] |= dp1[j] && dp2[j + newLength];
                    dp[length][i][j] |= dp1[j + length - newLength] && dp2[j];
                }
            }
        }
    }
    return dp[n][0][0];
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
    // cin>>test;
    while (test--)
    {
        string s1, s2;
        getline(cin >> ws, s1);
        getline(cin >> ws, s2);

        cout << isScramble(s1, s2);
    }
    return 0;
}