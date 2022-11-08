#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

struct data
{
    ll start;
    ll end;
    ll price;
};

bool comp(struct data a, struct data b)
{
    if (a.end < b.end)
    {
        return true;
    }
    else if (a.end == b.end)
    {
        return a.start < b.start;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<struct data> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].start >> a[i].end >> a[i].price;
    }
    sort(a.begin(), a.end(), comp);
    vector<ll> endTimes(n);
    for (int i = 0; i < n; i++)
    {
        endTimes[i] = a[i].end;
    }
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int ind = (int)(lower_bound(endTimes.begin(), endTimes.end(), a[i - 1].start) - endTimes.begin());
        dp[i] = (ll)max(dp[ind] + a[i - 1].price, dp[i - 1]);
    }
    cout << dp[n];
    return 0;
}