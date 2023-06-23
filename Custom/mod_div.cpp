#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}