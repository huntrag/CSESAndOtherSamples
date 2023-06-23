#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<int, int>>> vvpi;
typedef vector<vector<pair<ll, ll>>> vvpll;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

// int calculateMinimumHP(vector<vector<int>> &a)
// {
//     int n = a.size();
//     int m = a[0].size();
//     vvpll dp(n, vpll(m));

//     dp[0][0] = make_pair(a[0][0], a[0][0]);

//     for (int i = 1; i < m; i++)
//     {
//         ll mx = dp[0][i - 1].second;
//         ll sum = dp[0][i - 1].first + a[0][i];
//         dp[0][i] = make_pair(sum, min(mx, sum));
//     }
//     for (int i = 1; i < n; i++)
//     {
//         ll mx = dp[i - 1][0].second;
//         ll sum = dp[i - 1][0].first + a[i][0];
//         dp[i][0] = make_pair(sum, min(mx, sum));
//     }
//     ll u1, u2, l1, l2, c1, c2;
//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j < m; j++)
//         {
//             u1 = dp[i - 1][j].first;
//             u2 = dp[i - 1][j].second;
//             l1 = dp[i][j - 1].first;
//             l2 = dp[i][j - 1].second;

//             if (u2 > l2)
//             {
//                 c1 = u1 + a[i][j];
//                 c2 = min(c1, u2);
//             }
//             else if (u2 < l2)
//             {
//                 c1 = l1 + a[i][j];
//                 c2 = min(c1, l2);
//             }
//             else
//             {
//                 if (l1 > u1)
//                 {
//                     c1 = l1 + a[i][j];
//                     c2 = min(c1, l2);
//                 }
//                 else
//                 {
//                     c1 = u1 + a[i][j];
//                     c2 = min(c1, u2);
//                 }
//             }
//             dp[i][j] = make_pair(c1, c2);
//         }
//     }
//     ll mn = dp[n - 1][m - 1].second;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << setw(2) << "(" << dp[i][j].first << ", " << dp[i][j].second << ") ";
//         }
//         cout << "\n";
//     }

//     if (mn >= 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return -mn + 1;
//     }
// }

int calculateMinimumHP(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();

    vll dp(m + 1, LLONG_MAX);
    dp[m - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            ll t = min(dp[j], dp[j + 1]) - a[i][j];
            dp[j] = max(t, 1ll);
        }
    }
    return dp[0];
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
        int n, m;
        cin >> n >> m;
        vvi a(n, vi(m));
        for (auto &r : a)
        {
            for (auto &c : r)
            {
                cin >> c;
            }
        }
        cout << calculateMinimumHP(a);
    }
    return 0;
}