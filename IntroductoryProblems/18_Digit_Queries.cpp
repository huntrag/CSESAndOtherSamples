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
    int test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        ll max = LLONG_MAX;
        ll lower_bound = 0ll;
        ll digits = 1ll;
        ll tens = 1ll;
        while (lower_bound + digits * tens * 9ll < max && lower_bound + digits * tens * 9 < n)
        {

            lower_bound += digits * tens * 9ll;
            tens *= (ll)10ll;
            digits = (ll)digits + 1ll;
            // cout << lower_bound << "\n";
        }
        ll number = (ll)tens - 1ll + ceil((long double)(n - lower_bound) / (digits));
        ll place = (ll)(n - lower_bound) % digits;
        place = (place == 0) ? digits : place;
        place = digits - place;
        tens = 1ll;
        while (place)
        {
            tens *= (ll)10;
            place = place - 1ll;
        }
        cout /*<< number << " "*/ << (ll)(number / tens) % 10 << "\n";
    }
    return 0;
}