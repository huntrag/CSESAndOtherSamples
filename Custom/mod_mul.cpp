#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

ll modMul(ll a, ll b)
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}