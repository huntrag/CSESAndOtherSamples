#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        return a.second < b.second;
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
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }

    sort(a.begin(), a.end(), comp);
    ll cur = 0, profit = 0;
    for (ll i = 0; i < n; i++)
    {
        cur += (ll)a[i].first;
        profit += (ll)(a[i].second - cur);
    }

    cout << profit;

    return 0;
}