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
    int n, m, k;
    cin >> n >> m >> k;
    int an[n];
    int am[m];

    for (int i = 0; i < n; i++)
    {
        cin >> an[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> am[i];
    }

    sort(an, an + n);
    sort(am, am + m);
    int j = 0, count = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        while (j < m && an[i] - k > am[j])
        {
            j++;
        }
        if (j < m && an[i] + k >= am[j])
        {
            count++;
            j++;
        }
    }
    cout << count;

    return 0;
}