#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<ll, ll> freq;
    ll distinct = 0;
    ll j = 0;
    ll total = n;
    ll last = 0;
    for (ll i = 0; i < n; i++)
    {
        freq[a[i]] += 1;
        if (freq[a[i]] == 1)
            distinct += 1;
        if (distinct > k)
        {
            ll len = i - j;
            ll b = last - j + 1;
            ll add = len * (len - 1) / 2 - b * (b - 1) / 2;
            last = i - 1;
            total += add;
            while (distinct > k)
            {
                freq[a[j]] -= 1;
                if (freq[a[j]] == 0)
                    distinct -= 1;
                j += 1;
            }
        }
    }
    ll len = n - j;
    ll b = last - j + 1;
    total += len * (len - 1) / 2 - b * (b - 1) / 2;
    cout << total;

    return 0;
}