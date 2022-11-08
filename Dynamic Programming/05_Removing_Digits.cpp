#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int sol(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    int minimum = INT_MAX;
    int temp = n;
    while (n > 0)
    {
        if (n % 10 > 0)
        {
            if (dp[temp - (n % 10)] == -1)
            {
                dp[temp - (n % 10)] = sol(temp - (n % 10), dp);
            }
            minimum = min(minimum, 1 + dp[temp - (n % 10)]);
        }
        n = n / 10;
    }
    return minimum;
}

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
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    int count = sol(n, dp);
    cout << count;
    return 0;
}