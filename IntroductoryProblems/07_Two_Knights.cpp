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

    ll n;
    cin >> n;
    // First select no of 2x3 and 3x2 squares so that we can
    // visualize knights attacking each other
    // The answer is n^2(n^2−1)/2−2*2*(n−1)(n−2)

    for (ll i = 1; i <= n; i++)
    {
        ll x = (ll)i * i;
        x = (ll)(x * x - 9 * x) / 2ll;
        cout << (ll)x + 12 * i - 8 << "\n";
    }

    return 0;
}