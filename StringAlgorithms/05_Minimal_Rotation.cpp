// Did using rolling hashing and also binary search O(nlogn)
// While also varient of kmp called as booth's algorithm O(n)

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

#define char2ind(c) ((ll)c - (ll)'a')

vector<ll> inv;
vll h;

ll mpow(ll a, ll b)
{
    a = (a % MOD);
    b = (b % MOD);
    ll ans = 1;
    while (b > 0)
    {
        if ((b & 1))
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = (ll)b / 2;
    }

    return (ans) % MOD;
}

string booths(string s)
{
    int n = s.length();
    vector<int> f(2 * n, -1);
    int k = 0;
    int i;
    for (int j = 1; j < 2 * n; j++)
    {
        i = f[j - k - 1];

        while (i != -1 and s[j % n] != s[(k + i + 1) % n])
        {
            if (s[j % n] < s[(k + i + 1) % n])
            {
                k = j - i - 1;
            }
            i = f[i];
        }

        if (i == -1 and s[j % n] != s[(k + i + 1) % n])
        {
            if (s[j % n] < s[(k + i + 1) % n])
            {
                k = j;
            }
            f[j - k] = -1;
        }
        else
        {
            f[j - k] = i + 1;
        }
    }
    return s.substr(k) + s.substr(0, k);
}

void storeinv()
{
    int n = inv.size();
    inv[n - 1] = mpow(mpow(131ll, n - 1), MOD - 2);

    for (int i = n - 2; i >= 0; i--)
    {
        inv[i] = (inv[i + 1] * 131ll) % MOD;
    }
}

void rollinghash(string s)
{
    ll x = 1;
    int n = h.size() - 1;
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] + x * (ll)char2ind(s[i])) % MOD;
        x = (ll)(x * 131ll) % MOD;
    }
}

ll geth(ll l, ll r)
{
    return (ll)((h[r] - h[l - 1] + MOD) * inv[l - 1]) % MOD;
}

string solve(string s)
{
    s = s + s;
    ll n = s.length() / 2;

    h.resize(s.length());
    inv.resize(n + 1);
    rollinghash(s);
    storeinv();
    ll k = 1;

    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << h[i] << " ";
    // }
    // cout << "\n";

    for (ll i = 2; i <= n; i++)
    {
        ll lo = 0, hi = n - 1;

        while (lo <= hi)
        {
            ll lm = (lo + hi) / 2;

            if (geth(i, i + lm) == geth(k, k + lm))
            {
                lo = lm + 1;
            }
            else
            {
                hi = lm - 1;
            }
        }

        if (lo <= n - 1)
        {
            // cout << i << " " << k << " " << lo << " " << s[i + lo - 1] << " "
            //      << s[k + lo - 1] << "\n";
            if (char2ind(s[i + lo - 1]) < char2ind(s[k + lo - 1]))
            {
                k = i;
            }
        }
    }
    // cout << s << "\n";
    return s.substr(k - 1, n);
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
    // cin >> test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        cout << booths(s);
        // cout << solve(s);
    }
    return 0;
}