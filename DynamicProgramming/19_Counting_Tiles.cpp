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

int n, m;

ll dp[1002][(1 << 12)];

void gen(int mask, int cov, int i, vector<int> &nxt)
{
    nxt.push_back(mask);
    for (int j = i; j <= n; j++)
    {
        if ((mask & cov) == cov)
        {
            gen((mask ^ cov), cov * 4, i + 2, nxt);
        }
        cov = cov * 2;
    }
}

ll solve(int col, int mask)
{
    if (col == m)
    {
        if (mask == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (dp[col][mask] != -1)
    {
        return dp[col][mask];
    }

    vector<int> nxt;
    int al = (1 << n) - 1;
    gen((mask ^ al), 3, 1, nxt);
    ll count = 0;

    for (auto &r : nxt)
    {
        count = (count + solve(col + 1, r)) % MOD;
    }

    return dp[col][mask] = count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        cin >> n >> m;
        for (auto &x : dp)
        {
            for (auto &y : x)
            {
                y = -1;
            }
        }
        cout << solve(0, 0);
    }
    return 0;
}