#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll q;
    cin >> q;
    vector<ll> a(n);
    vector<ll> count(62);
    count[0] = 1;
    for (int i = 1; i < 62; i++)
    {
        count[i] = (ll)count[i - 1] * 2;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mx = floor((long double)log2(n));
    vector<vector<ll>> tb(n, vector<ll>(mx + 1));
    for (ll i = 0; i < n; i++)
    {
        tb[i][0] = a[i];
    }
    for (ll j = 1; j <= mx; j++)
    {
        for (ll i = 0; i + (count[j]) - 1 < n; i++)
        {
            tb[i][j] = max((ll)tb[i][j - 1], (ll)tb[i + (count[j - 1])][j - 1]);
        }
    }

    ll ans = 0;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        ll orig = x;
        ll sz = y - x + 1;
        ll cnt = 0;
        ll mn = LLONG_MIN;
        ll i = x;
        for (; sz > 0;)
        {
            if (sz & (count[cnt]))
            {
                mn = max(mn, tb[i][cnt]);
                i += (count[cnt]);
                sz -= (count[cnt]);
            }
            cnt++;
        }
        cout << a[x] << " " << mn << "\n";
        (a[x] == mn) ? (ans += 1) : (ans += 0);
    }
    cout << ans;
    return 0;
}