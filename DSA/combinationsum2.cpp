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

void backtrack(vi &a, vi &comb, int rem, int cur, vvi &res)
{
    if (rem == 0)
    {
        res.push_back(comb);
        return;
    }

    for (int i = cur; i < a.size(); i++)
    {
        if (i > cur && a[i] == a[i - 1])
        {
            continue;
        }
        int pick = a[i];

        if (rem - pick < 0)
        {
            break;
        }

        comb.push_back(pick);
        backtrack(a, comb, rem - pick, i + 1, res);
        comb.pop_back();
    }
}

vvi combinationSum2(vi &a, int t)
{
    vvi results;
    vi comb;
    sort(a.begin(), a.end());

    backtrack(a, comb, t, 0, results);
    return results;
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
        int t;
        cin >> t;
        vi a;
        int x;
        while (cin >> x)
        {
            a.push_back(x);
        }
        vvi ans = combinationSum2(a, t);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}