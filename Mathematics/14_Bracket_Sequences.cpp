#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
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
    ll n;
    cin >> n;
    if (n % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    if (n == 2)
    {
        cout << 1;
    }
    else if (n == 4)
    {
        cout << 2;
    }
    else
    {
        ll ans = 2;
        for (int i = 6; i <= n; i += 2)
        {
            ans = (3 * (ans - 1) - 1) % MOD;
        }
        cout << ans;
    }
    return 0;
}