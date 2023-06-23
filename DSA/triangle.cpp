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

int triangle(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n);
    dp[0].resize(1);
    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i].resize(i + 1);
        dp[i][0] = dp[i - 1][0] + a[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = a[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        dp[i][i] = a[i][i] + dp[i - 1][i - 1];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < dp[i].size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
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
        int n;
        cin >> n;
        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }

        cout << triangle(a);
    }
    return 0;
}