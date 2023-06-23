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

vector<int> suffix;

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
    int tot = 0;
    int mx = INT_MIN;
    for (int i = ind; i < n && i < ind + 3; i++)
    {
        tot += a[i];
        mx = max(mx, tot + get(a, i + 1));
    }
    // cout << ind << " " << mx << "\n";
    dp[ind] = suffix[ind] - mx;
    vis[ind] = true;
    return dp[ind];
}

string stoneGameIII(vector<int> &a)
{
    int n = a.size();
    suffix.resize(n);
    dp.resize(n);
    vis.resize(n);
    for (int i = 0; i < n; i++)
    {
        vis[i] = false;
    }
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + a[i];
    }
    int bob = get(a, 0);
    int alice = suffix[0] - bob;

    if (alice == bob)
    {
        return "Tie";
    }
    else if (alice > bob)
    {
        return "Alice";
    }
    else
    {
        return "Bob";
    }
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
        cout << stoneGameIII(a);
    }
    return 0;
}