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

vll conv(ll a)
{
    vll arr;
    while (a > 0)
    {
        arr.push_back(a % 10);
        a = a / 10;
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

ll dp[20][10][2][2];

ll solve(ll ind, ll prev, bool tight, bool start, vll &arr)
{
    if (ind >= arr.size())
    {
        return 0;
    }
    if (dp[ind][prev][tight][start] != -1)
    {
        return dp[ind][prev][tight][start];
    }
    ll count = 0;
    ll lim = 9;
    if (tight)
    {
        lim = arr[ind];
    }
    for (int i = 0; i <= lim; i++)
    {
        bool tig = false;
        if (i == lim)
        {
            tig = tight;
        }
        // cout << ind << " " << prev << " " << i << "\n";
        if (i == prev && start)
        {
            if (tig)
            {
                ll num = 0;
                for (int j = ind + 1; j < arr.size(); j++)
                {
                    num = num * 10 + arr[j];
                }
                num++;
                // cout << ind << " " << prev << " " << num << "\n";
                count += num;
            }
            else
            {
                ll num = 1;
                for (int j = ind + 1; j < arr.size(); j++)
                {
                    num = num * 10;
                }
                // cout << ind << " " << prev << " " << num << "\n";
                count += num;
            }
        }
        else
        {
            count += solve(ind + 1, i, tig, (start | (i > 0)), arr);
        }
    }
    // cout << ind << " " << prev << " " << tight << " " << count << "\n";
    dp[ind][prev][tight][start] = count;
    return count;
}

ll solve(ll a)
{
    if (a <= 0)
    {
        return a == 0;
    }
    vll arr = conv(a);
    for (auto &x : dp)
    {
        for (auto &y : x)
        {
            for (auto &z : y)
            {
                z[0] = -1;
                z[1] = -1;
            }
        }
    }
    return a - solve(0, 0, true, false, arr) + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        ll a, b;
        cin >> b >> a;
        cout << solve(a) - solve(b - 1);
    }
    return 0;
}