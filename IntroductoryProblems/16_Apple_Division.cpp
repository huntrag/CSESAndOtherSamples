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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll mn = INT64_MAX;
    int cnt = 1 << n;
    if (n == 1)
    {
        cout << a[0];
        return 0;
    }
    for (int i = 1; i < cnt - 1; i++)
    {
        ll sum1 = 0;
        for (int j = 0; j < n; j++)
        {
            int x = (1 << j);
            // cout << (x);
            if (i & (1 << j))
            {
                sum1 += a[j];
            }
        }
        // cout << sum1 << " " << sum - sum1 << "\n";
        mn = min(mn, abs((sum - sum1) - sum1));
    }
    cout << mn;

    return 0;
}