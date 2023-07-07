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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int k = ceil(log2(MOD) + 0.0);
        int n, q;
        cin >> n >> q;
        vector<vector<int>> seq(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            seq[0][i] = i;
            cin >> seq[1][i];
        }

        for (int i = 2; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                seq[i][j] = seq[i - 1][seq[i - 1][j]];
            }
        }

        while (q--)
        {
            int x, steps;
            cin >> x >> steps;

            int cur = x;
            int cur_step = 1;
            while (steps > 0)
            {
                if ((steps & 1))
                {
                    cur = seq[cur_step][cur];
                }
                steps = steps / 2;
                cur_step++;
            }
            cout << cur << "\n";
        }
    }
    return 0;
}