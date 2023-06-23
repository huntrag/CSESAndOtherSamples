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

int dp[201][101][2];

bool isInterleave1(string s1, string s2, string s3)
{

    if (s3.length() != s1.length() + s2.length())
        return false;

    bool table[s1.length() + 1][s2.length() + 1];

    for (int i = 0; i < s1.length() + 1; i++)
        for (int j = 0; j < s2.length() + 1; j++)
        {
            if (i == 0 && j == 0)
                table[i][j] = true;
            else if (i == 0)
                table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            else if (j == 0)
                table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
            else
                table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }

    return table[s1.length()][s2.length()];
}

bool solve(string s1, string s2, string t, int ind, int r)
{
    int n = s1.length(), m = t.length();

    if (dp[m][n][ind - 1] != -1)
    {
        return dp[m][n][ind - 1];
    }
    // cout << r << " " << ind << " | " << s1 << " - " << s2 << " - " << t << "\n";
    if (n == 0 && m == 0)
    {
        dp[0][0][ind - 1] = true;
        return true;
    }
    int i = 0;
    int j = 0;
    bool ans = false;
    while (i < n && j < m)
    {
        if (s1[i] != t[j])
        {
            break;
        }
        else
        {
            ans = ans | solve(s2, s1.substr(i + 1), t.substr(j + 1), (1 + ((ind - 1) ^ 1)), r + 1);
        }
        i++;
        j++;
    }
    dp[m][n][ind - 1] = ans;
    // cout << m << "\n";
    return ans;
}

bool isInterleave(string s1, string s2, string s3)
{
    if (s1.length() + s2.length() != s3.length())
    {
        return false;
    }
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    bool ans2 = solve(s2, s1, s3, 2, 0);
    if (ans2 == true)
    {
        return ans2;
    }
    // cout << "---------------------------\n";
    for (int i = 0; i <= 200; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    bool ans1 = solve(s1, s2, s3, 1, 0);
    return ans1;
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
        string s1, s2, s3;
        getline(cin >> ws, s1);
        getline(cin >> ws, s2);
        getline(cin >> ws, s3);

        cout << isInterleave(s1, s2, s3);
    }
    return 0;
}