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

vector<int> dp;
vector<bool> vis;

int get(vector<int> &a, int ind)
{
    int n = a.size();
    if (ind == n)
    {
        return 0;
    }
    if (vis[ind])
    {
        return dp[ind];
    }
    int mx = 0;
    for (int i = ind; i < n; i++)
    {
        mx = max(mx, ((a[i] - a[ind]) + get(a, i + 1)));
    }
    vis[ind] = true;
    dp[ind] = mx;
    return mx;
}

int maxProfitDP(vector<int> &a)
{
    int n = a.size();
    dp.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }
    int mx = get(a, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << dp[i] << "\n";
    // }
    return mx;
}

int maxProfit(vector<int> &a)
{
    int n = a.size();
    int count = 0;
    int pivot = a[0];
    if (n == 1)
    {
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            continue;
        }
        else
        {
            count = count + (a[i - 1] - pivot);
            pivot = a[i];
        }
    }
    if (a[n - 1] >= a[n - 2])
    {
        count = count + (a[n - 1] - pivot);
    }
    return count;
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