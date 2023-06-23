#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

// Binary exponention

int modmul(int a, int b, int mod)
{
    int prod = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            prod = (prod + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }

    return prod;
}

ll power(ll a, ll b, ll mod)
{
    ll prod = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            prod = (prod * a) % mod;
        }
        a = (a * a) % mod;

        b >>= 1;
    }

    return prod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        int a, b;
        cin >> a >> b;
        cout << power(a, b, MOD) << "\n";
    }
    return 0;
}