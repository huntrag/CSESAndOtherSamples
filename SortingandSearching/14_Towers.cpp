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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(m.begin(), m.end(), a[i]);
        if (it == m.end())
        {
            m.push_back(a[i]);
        }
        else
        {
            *(it) = a[i];
        }
    }
    cout << m.size();
    return 0;
}