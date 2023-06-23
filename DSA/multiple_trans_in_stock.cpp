#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

void print(int x)
{
    cout << setw(3) << x << " ";
}

int tlemaxProfit(int K, int n, int a[])
{
    // code here
    K = min(K, n / 2);
    int dp[K + 1][n][n];
    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    // for k=1;
    for (int i = 0; i < n; i++)
    {
        int mn = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < mn)
            {
                mn = a[j];
                dp[1][i][j] = dp[1][i][j - 1];
                continue;
            }
            dp[1][i][j] = max(dp[1][i][j - 1], a[j] - mn);
        }
    }

    for (int k = 2; k <= K; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2 * (k)-1; j < n; j++)
            {
                dp[k][i][j] = dp[k - 1][i][j];
                for (int m = i; m <= j - 1; m++)
                {
                    dp[k][i][j] = max(dp[k - 1][i][m] + dp[1][m + 1][j], dp[k][i][j]);
                }
            }
        }
    }
    for (int k = 1; k <= K; k++)
    {
        cout << k << " -----------------------\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                print(dp[k][i][j]);
            }
            cout << "\n";
        }
    }

    return dp[K][0][n - 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << tlemaxProfit(k, n, arr);

    return 0;
}