#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
// #define MOD 1000000007
#define fi first
#define se second

int numberOfUniqueGoodSubsequences(string s)
{
    int MOD = 1000000007;
    int dp[2] = {0, 0};
    int flag = 0;
    for (auto c : s)
    {
        if (c == '0')
        {
            flag = 1;
        }
        dp[c - '0'] = (dp[0] + dp[1] + c - '0') % MOD;
    }

    return (dp[0] + dp[1] + flag) % MOD;
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
        string s;
        getline(cin >> ws, s);
        cout << numberOfUniqueGoodSubsequences(s);
    }
    return 0;
}