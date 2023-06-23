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
        ll n;
        cin >> n;
        vll a(n);
        for (auto &r : a)
        {
            cin >> r;
        }
        ll mxi = *max_element(a.begin(), a.end());
        ll mask = 1ll;
        ll mx = -1;
        for (ll i = 0; i < 63; i++)
        {
            if ((mxi & mask) > 0)
            {
                mx = max(mx, i);
            }
            mask = (ll)mask * 2ll;
            // cout << mask << "\n";
        }
        // mask = (1 << mx);
        mask = 1ll;
        for (ll i = 1; i <= mx; i++)
        {
            mask = (ll)mask * 2ll;
        }
        // cout << mx << "\n";
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            if ((a[i] & mask) > 0)
            {
                count++;
            }
        }

        cout << ceil((long double)count / 2) << "\n";
    }
    return 0;
}