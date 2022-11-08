#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

ll power(ll n, ll m)
{
    ll res = 1ll;
    while (m > 0)
    {
        if (m % 2 == 1)
        {
            res = (ll)(res * n) % MOD;
        }
        n = (ll)(n * n) % MOD;
        m /= 2;
    }

    return res;
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
    cout << power(2, n);
    return 0;
}