#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int total = (1 << (n));
    vector<pair<ll, ll>> dp(total, {MOD, MOD});
    dp[0] = mp(0, 0);
    for (int i = 1; i < total; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = (1 << (j));
            if ((i & x) > 0)
            {
                pair<int, int> p;
                if (dp[i - x].se + a[j] > k)
                {
                    p.fi = dp[i - x].fi + 1;
                    p.se = a[j];
                }
                else if (dp[i - x].se + a[j] == k)
                {
                    p.fi = dp[i - x].fi + 1;
                    p.se = 0;
                }
                else
                {
                    p.fi = dp[i - x].fi;
                    p.se = dp[i - x].se + a[j];
                }
                if (dp[i].fi > p.fi)
                {
                    dp[i].fi = p.fi;
                    dp[i].se = p.se;
                }
                else if (dp[i].fi == p.fi)
                {
                    dp[i].se = min((int)dp[i].se, p.se);
                }
            }
        }
    }
    if (dp[total - 1].se > 0)
    {
        dp[total - 1].fi += 1;
    }
    cout << dp[total - 1].fi;
    return 0;
}