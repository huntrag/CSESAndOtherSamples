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
#define i2c(i) ((char)('A' + i))

int n, m;
vi lps;
string s;
int cnt;

void createlps(string p)
{
    int i = 0, j = 1;
    lps.resize(m);
    while (j < m)
    {
        if (p[j] != p[i])
        {
            if (i == 0)
            {
                lps[j] = i;
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
        else
        {
            i++;
            lps[j] = i;
            j++;
        }
    }
}

ll mpow(ll a, ll b, ll mod)
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

void build(int i, int l)
{
    if (i == n)
    {
        return;
    }
    int x;

    for (int j = 0; j < 26; j++)
    {
        if (i2c(j) == s[l])
        {
            if (l == m - 1)
            {
                cnt = (cnt + mpow(26, n - i - 1, MOD)) % MOD;
            }
            else
            {
                build(i + 1, l + 1);
            }
        }
        else
        {
            x = l;
            while (x > 0 && s[x] != i2c(j))
            {
                x = lps[x - 1];
            }
            if (x == 0 && s[x] != i2c(j))
            {
                build(i + 1, x);
            }
            else
            {
                build(i + 1, x + 1);
            }
        }
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
    // cin >> test;
    while (test--)
    {
        cin >> n;

        getline(cin >> ws, s);
        m = s.length();
        createlps(s);
        for (int i = 0; i < lps.size(); i++)
        {
            cout << lps[i] << " ";
        }
        cnt = 0;
        build(0, 0);
    }
    return 0;
}