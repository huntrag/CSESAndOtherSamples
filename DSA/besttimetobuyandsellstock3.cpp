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

int maxProfit(vector<int> &a)
{
    int n = a.size();
    vector<int> prefixMin(n), suffixMax(n);

    prefixMin[0] = a[0];
    suffixMax[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefixMin[i] = min(prefixMin[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], a[i]);
    }
    vector<int> dp1(n), dp2(n);

    dp1[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp1[i] = max(dp1[i - 1], a[i] - prefixMin[i]);
    }
    dp2[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dp2[i] = max(dp2[i + 1], suffixMax[i] - a[i]);
    }
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, dp1[i] + dp2[i]);
    }
    return mx;
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
        vector<int> a;
        int x;
        while (cin >> x)
        {
            a.push_back(x);
        }

        cout << maxProfit(a);
    }
    return 0;
}