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

short m[2001][2001];

bool isMatchRec(string s, string r)
{
    if (m[s.length()][r.length()] > 0)
    {
        return (bool)(m[s.length()][r.length()] - 1);
    }
    bool flag = false;
    bool next = true;
    if (s.length() == 0 && r.length() == 0)
    {
        flag = true;
    }
    else if (s.length() == 0 && r.length() > 0)
    {
        if (r[0] == '*')
        {
            flag = true;
            next = isMatchRec(s, r.substr(1));
        }
        else
        {
            next = false;
        }
    }
    else if (s[0] == r[0] || (r[0] == '?'))
    {
        flag = true;
        next = isMatchRec(s.substr(1), r.substr(1));
    }
    else if (r[0] == '*')
    {
        flag = true;
        next = isMatchRec(s.substr(1), r.substr(1)) || isMatchRec(s, r.substr(1)) || isMatchRec(s.substr(1), r);
    }

    // cout << s << " " << r << " " << (flag && next) << "\n";
    m[s.length()][r.length()] = 1 + (short)(flag && next);

    return (flag && next);
}

bool isMatch(string s, string r)
{
    int n = s.length();
    int m = r.length();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    int x = 0;
    while (r[x] == '*')
    {
        dp[0][x + 1] = true;
        x++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == r[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (r[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (r[j - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
        }
    }

    // cout << setw(2) << "*"
    //      << " ";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << setw(2) << r[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << setw(2) << s[i - 1] << " ";
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << setw(2) << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

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

        cout << isMatch(s, r);
    }
    return 0;
}