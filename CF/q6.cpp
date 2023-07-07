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
#define MAX 1000000000000000001

ll mpow(ll a, ll b)
{
    ll prod = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            prod = (prod * a);
        }
        a = (a * a);

        b >>= 1;
    }

    return prod;
}

ll trans(ll x, ll p)
{
    return x * (p - 1) + 1;
}

ll logy(ll x, ll p)
{
    return (ll)floor((double)(log10(trans(x, p)) + 0.0) / (log10(p) + 0.0));
}

ll cal(ll v, ll p)
{
    return (mpow(v, p) - 1) / (p - 1);
}

bool dhang(ll ans, ll x)
{

    ll pw = x * x;
    ll init = 1 + x;
    init = init + pw;
    ll sum = init;
    while (sum <= ans)
    {
        if (sum == ans)
        {
            return true;
        }
        pw = pw * x;
        sum = sum + pw;
    }
    return false;
}

bool search(ll x, ll low, ll high, ll llo, ll lhi)
{
    if (high - low <= 1)
    {
        return dhang(x, low) | dhang(x, high);
    }
    ll mid = (low + high) / 2;
    ll mind = logy(MAX, mid);
    ll lm = min(((llo + lhi) / 2), mind);
    ll ret = cal(mid, lm);

    if (ret == x)
    {
        return true;
    }
    else if (ret > x)
    {
        return search(x, low, mid, llo, lhi) | search(x, mid, high, llo, lm);
    }
    else
    {
        return search(x, low, mid, lm, lhi) | search(x, mid, high, llo, lhi);
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
    int test = 1;
    cin >> test;
    while (test--)
    {
        ll x;
        cin >> x;

        ll low = 2, high = MOD;

        ll llo = 2;
        ll lhi = logy(x, 2);

        if (search(x, low, high, llo, lhi))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}