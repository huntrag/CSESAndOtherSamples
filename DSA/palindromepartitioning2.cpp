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

vector<vector<int>> dp;

vector<pair<int, bool>> dp1;

int solve(string s, int ind)
{
    if (ind >= s.size())
    {
        return 0;
    }
    if (dp1[ind].second)
    {
        return dp1[ind].first;
    }
    int mn = INT_MAX;
    for (int i = 0; i < dp[ind].size(); i++)
    {
        mn = min(mn, 1 + solve(s, ind + dp[ind][i]));
    }

    dp1[ind].first = mn;
    dp1[ind].second = true;

    return mn;
}

int minCut(string s)
{
    int n = s.length();
    dp.resize(n);
    dp1.resize(n);
    // odd palindromes
    for (int i = 0; i < n; i++)
    {
        // i is the middle eleme

        for (int dis = 0; (i - dis) >= 0 && (i + dis) < n; dis++)
        {
            if (s[i - dis] == s[i + dis])
            {
                dp[i - dis].push_back(2 * dis + 1);
            }
            else
            {
                break;
            }
        }
    }
    // for even palin
    for (int i = 0; i < n - 1; i++)
    {
        // i and i+1 middle elem
        for (int diff = 0; (i - diff) >= 0 && (i + diff + 1) < n; diff++)
        {
            if (s[i - diff] == s[i + diff + 1])
            {
                dp[i - diff].push_back(2 * diff + 2);
            }
            else
            {
                break;
            }
        }
    }

    return solve(s, 0) - 1;
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
        string s;
        getline(cin >> ws, s);
        cout << minCut(s);
    }
    return 0;
}