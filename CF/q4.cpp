#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

void solve(vll &a, int l, int r, string s, ll &sum, ll &count, vll &prefix)
{
    if (s.length() == 0 || l == r)
    {
        // cout << l << " " << r << "\n";
        count++;
        if (l == 0)
        {
            sum += (prefix[r]);
        }
        else
        {
            sum += (prefix[r] - prefix[l - 1]);
        }
        return;
    }
    if (s[0] == 'L')
    {
        for (int i = l; i < r; i++)
        {
            solve(a, l, i, s.substr(1), sum, count, prefix);
        }
    }
    else
    {
        for (int i = l + 1; i <= r; i++)
        {
            solve(a, i, r, s.substr(1), sum, count, prefix);
        }
    }
}

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
        multiplicand = multiplicand / 2;
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

ll modinv(ll a)
{
    return modMul(a, MOD - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        ll n, m;
        cin >> n >> m;
        vll a(n);
        vll prefix(n);
        for (auto &r : a)
        {
            cin >> r;
        }

        prefix[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i];
        }
        string s;
        getline(cin >> ws, s);

        ll sum = 0;
        ll count = 0;
        solve(a, 0, n - 1, s, sum, count, prefix);
        // cout << sum << " " << count << " ";
        ll ans = (sum * mod_inv(count)) % MOD;
        cout << ans << "\n";
    }
    return 0;
}