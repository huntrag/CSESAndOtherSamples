#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll mn = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ll r = mn * k;
    ll l = 0;
    ll mid = (l + r) / 2;
    while (mid != r - 1)
    {
        ll products = 0;
        mid = (l + r) / 2;
        for (ll i = 0; i < n; i++)
        {
            products += (ll)mid / a[i];
        }
        // cout << l << " " << r << " " << products << "\n";
        if (products >= k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    ll products = 0;
    for (ll i = 0; i < n; i++)
    {
        products += (ll)mid / a[i];
    }
    if (products >= k)
    {
        cout << mid;
        return 0;
    }
    cout << r;
    return 0;
}