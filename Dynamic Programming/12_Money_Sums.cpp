#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<bool> dp(sum + 1, false);
    vector<bool> prev(sum + 1, false);
    prev[0] = dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j - a[i] >= 0)
            {
                dp[j] = dp[j] | prev[j - a[i]];
            }
        }
        for (int j = 1; j <= sum; j++)
        {
            prev[j] = dp[j];
        }
    }
    vector<int> ans;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[i])
        {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}