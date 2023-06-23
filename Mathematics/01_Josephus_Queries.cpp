#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

ll joss(ll n, ll k)
{
    if (n == 1)
    {
        return 1;
    }
    if (k <= (n + 1) / 2)
    {
        if (2 * k > n)
        {
            return 1;
        }
        else
        {
            return 2 * k;
        }
    }
    ll temp = joss(n / 2, k - (n + 1) / 2);
    // Below case for 3
    if (n % 2 == 1)
        return 2 * temp + 1;
    else
        // Below case for 1 as even numbers dont kill 1
        return 2 * temp - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        ll n, k;
        cin >> n >> k;
        cout << joss(n, k) << "\n";
    }
    return 0;
}