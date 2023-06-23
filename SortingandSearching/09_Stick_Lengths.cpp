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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll med;
    if (n % 2 == 0)
    {
        med = ceil((long double)(a[n / 2 - 1] + a[n / 2]) / 2);
    }
    else
    {
        med = a[n / 2];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (ll)abs(med - a[i]);
    }
    cout << ans;
    return 0;
}