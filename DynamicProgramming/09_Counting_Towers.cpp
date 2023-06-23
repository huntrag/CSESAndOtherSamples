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
    int q;
    cin >> q;
    vector<int> query(q);
    int n = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
        n = max(n, query[i]);
    }
    vector<vector<ll>> dp(20, vector<ll>(n + 1, 0));
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[8][1] = 1;
    dp[9][1] = 1;
    dp[13][1] = 1;
    dp[14][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[10][i - 1] + dp[11][i - 1] + dp[12][i - 1] + dp[14][i - 1]) % MOD;
        dp[1][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[10][i - 1] + dp[11][i - 1] + dp[12][i - 1] + dp[14][i - 1]) % MOD;
        dp[2][i] = (dp[6][i - 1] + dp[0][i - 1] + dp[16][i - 1] + dp[18][i - 1]) % MOD;
        dp[3][i] = (dp[5][i - 1] + dp[13][i - 1] + dp[17][i - 1] + dp[19][i - 1]) % MOD;
        dp[4][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[5][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[6][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[7][i] = (dp[1][i - 1] + dp[2][i - 1] + dp[3][i - 1] + dp[4][i - 1]) % MOD;
        dp[8][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[10][i - 1] + dp[14][i - 1] + dp[11][i - 1] + dp[12][i - 1]) % MOD;
        dp[9][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[10][i - 1] + dp[14][i - 1] + dp[11][i - 1] + dp[12][i - 1]) % MOD;
        dp[10][i] = (dp[8][i - 1] + dp[15][i - 1]) % MOD;
        dp[11][i] = (dp[6][i - 1] + dp[0][i - 1] + dp[16][i - 1] + dp[18][i - 1]) % MOD;
        dp[12][i] = (dp[5][i - 1] + dp[13][i - 1] + dp[17][i - 1] + dp[19][i - 1]) % MOD;
        dp[13][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[14][i - 1] + dp[10][i - 1] + dp[11][i - 1] + dp[12][i - 1]) % MOD;
        dp[14][i] = (dp[7][i - 1] + dp[9][i - 1] + dp[14][i - 1] + dp[10][i - 1] + dp[11][i - 1] + dp[12][i - 1]) % MOD;
        dp[15][i] = (dp[8][i - 1] + dp[15][i - 1]) % MOD;
        dp[16][i] = (dp[6][i - 1] + dp[0][i - 1] + dp[16][i - 1] + dp[18][i - 1]) % MOD;
        dp[17][i] = (dp[5][i - 1] + dp[13][i - 1] + dp[17][i - 1] + dp[19][i - 1]) % MOD;
        dp[18][i] = (dp[5][i - 1] + dp[13][i - 1] + dp[17][i - 1] + dp[19][i - 1]) % MOD;
        dp[19][i] = (dp[6][i - 1] + dp[0][i - 1] + dp[16][i - 1] + dp[18][i - 1]) % MOD;
    }
    for (int i = 0; i < q; i++)
    {
        int k = query[i];
        cout << (dp[7][k] + dp[9][k] + dp[10][k] + dp[11][k] + dp[12][k] + dp[14][k]) % MOD << "\n";
    }
    return 0;
}