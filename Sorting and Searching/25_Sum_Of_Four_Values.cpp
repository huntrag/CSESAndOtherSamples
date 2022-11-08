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
    ll x;
    cin >> n >> x;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        for (int l = n - 1; l >= i + 3; l--)
        {
            ll x2 = (ll)x - (a[i].first + a[l].first);
            for (int j = i + 1, k = l - 1; j < k; j++)
            {
                while (j < k && a[j].first + a[k].first > x2)
                {
                    k--;
                }
                if (j < k && a[j].first + a[k].first == x2)
                {
                    cout << a[i].second << " " << a[j].second << " " << a[k].second << " " << a[l].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}