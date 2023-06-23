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

bool isValid(vector<vector<int>> &grid, int i, int j)
{
    if (grid[i][j] == 1)
    {
        return false;
    }
    return true;
}

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int n, m;
    m = grid.size();
    n = grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isValid(grid, i, j))
            {
                if (isValid(grid, i - 1, j))
                {
                    dp[i + 1][j + 1] += dp[i][j + 1];
                }
                if (isValid(grid, i, j - 1))
                {
                    dp[i + 1][j + 1] += dp[i + 1][j];
                }
            }
        }
    }

    return dp[m][n];
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
        int n, m;
        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        cout << uniquePathsWithObstacles(a);
    }
    return 0;
}