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
        ll n, m, h;
        cin >> n >> m >> h;
        vll cars(n), power(m);

        for (auto &r : cars)
        {
            cin >> r;
        }
        for (auto &r : power)
        {
            cin >> r;
        }

        sort(cars.rbegin(), cars.rend());
        sort(power.rbegin(), power.rend());
        ll ans = 0;
        for (int i = 0; i < min(m, n); i++)
        {
            ans += (ll)min(cars[i], power[i] * h);
        }
        cout << ans << "\n";
    }

    return 0;
}