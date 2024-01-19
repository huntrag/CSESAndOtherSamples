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
#define MOD2 500000004

ll mpow(ll a, ll b)
{
    ll ans = 1;
    a = a % MOD;
    b = b % MOD;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b / 2;
    }
    return ans % MOD;
}

ll inv(ll a)
{
    return mpow(a, MOD - 2) % MOD;
}

ll apsum(ll st, ll end, ll diff)
{
    // ll idiff = inv(diff);
    ll num = (ll)(((end - st)) / diff);
    ll sum = ((num)*diff);
    ll formu1 = (ll)(((diff * (diff - 1))) * MOD2);
    diff = ((end) / diff);
    ll formu2 = (ll)(((diff * (diff + 1))) * MOD2);
    return (sum + formu2 - formu1) % MOD;
}

ll solve(ll n)
{
    ll sq = sqrt(n);
    // cout << sq << "\n";
    ll sum = 0;
    for (ll i = 1; i <= sq; i++)
    {
        sum = (sum + apsum(i * i, n, i)) % MOD;
    }
    return sum;
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
    // cin>>test;
    while (test--)
    {
        ll n;
        cin >> n;
        cout << solve(n);
    }
    return 0;
}