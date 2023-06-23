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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sliding Window

    int i = 0, j = 0;
    ll sum = 0, count = 0;
    while (j < n - 1 && i < n)
    {
        while (j < n - 1 && sum <= x)
        {
            if (i == j)
            {
                sum = a[i];
            }
            if (sum == x)
            {
                count++;
            }
            j++;
            sum += a[j];
        }
        while (i <= j && i < n && sum >= x)
        {
            if (i == j)
            {
                sum = a[i];
            }
            if (sum == x)
            {
                count++;
            }
            sum -= a[i];
            i++;
        }
    }
    cout << count;
    return 0;
}