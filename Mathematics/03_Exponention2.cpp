#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long MOD = 1e9 + 7;

ll exp(ll x, ll n, ll m)
{
    assert(n >= 0);
    x %= m;
    ll res = 1;
    while (n > 0)
    {
        if ((n & 1))
        { // if n is odd
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2; // divide by two
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll a;
        ll b;
        ll c;

        cin >> a >> b >> c;

        ll pow_bc = exp(b, c, MOD - 1);
        ll ans = exp(a, pow_bc, MOD);

        cout << ans << '\n';
    }
}