#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

// ########################################################

ll mod_mul(ll a, ll b);
ll gcd_extend(ll a, ll b, ll *x, ll *y);
ll mod_inv(ll b);
ll mod_div(ll a, ll b);
ll nCr(ll n, ll r);

ll nCr(ll n, ll r)
{
    if (r > n)
    {
        return 0;
    }

    if (r > n - r)
    {
        r = n - r;
    }

    ll ans = 1;

    for (ll i = 1; i <= r; i++)
    {
        ans = mod_mul(ans, n + i - 1);

        ans = mod_div(ans, i);
    }

    return ans;
}

ll mod_mul(ll a, ll b)
{
    ll multiplicand = min(a, b);
    ll multiplier = max(a, b);

    ll product = 0;

    while (multiplicand > 0)
    {
        if (multiplicand & 1 == 1)
        {
            product = (product + multiplier) % MOD;
        }
        multiplicand >>= 1;
        multiplier = (multiplier * 2) % MOD;
    }
    return product;
}

ll gcd_extend(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd_intmd = gcd_extend(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd_intmd;
}

ll mod_inv(ll b)
{
    ll x, y;
    ll gcd = gcd_extend(b, MOD, &x, &y);

    if (gcd != 1)
    {
        // fails fermat little
        return -1;
    }

    return (x % MOD + MOD) % MOD;
}

ll mod_div(ll a, ll b)
{
    a = a % MOD;
    ll inv = mod_inv(b);

    if (inv == -1)
    {
        // Division not defined
        return 0;
    }
    else
    {
        return (inv * a) % MOD;
    }
}

// ########################################################

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << nCr(4, 3);
    return 0;
}