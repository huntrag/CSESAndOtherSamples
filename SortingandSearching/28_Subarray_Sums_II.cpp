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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> mod(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (ll)a[i];
        mod[((sum % n) + n) % n]++;
    }
    ll count = 0;
    for (int i = 0; i < n; i++)
    {
        if (mod[i] > 1)
        {
            count += (ll)(mod[i]) * (mod[i] - 1) / 2;
        }
    }
    count += mod[0];
    cout << count;
    return 0;
}