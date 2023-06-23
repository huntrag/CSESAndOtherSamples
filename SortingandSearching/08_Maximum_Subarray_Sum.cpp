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
    ll sum = 0;
    ll mx = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = (ll)max((ll)sum + a[i], (ll)a[i]);
        mx = (ll)max(mx, sum);
    }
    cout << mx;
    return 0;
}