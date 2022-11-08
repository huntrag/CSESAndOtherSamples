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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        a[i] = make_pair(y, i);
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i].fi + a[j].fi < x)
        {
            i++;
        }
        else if (a[i].fi + a[j].fi > x)
        {
            j--;
        }
        else
        {
            cout << a[i].se + 1 << " " << a[j].se + 1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}