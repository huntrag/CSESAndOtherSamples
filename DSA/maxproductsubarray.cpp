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

int maxProduct(vector<int> &a)
{
    int mn = a[0], mx = a[0];
    int tot = a[0];
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
        {
            swap(mn, mx);
            mx = max(mx * a[i], a[i]);
            mn = min(mn * a[i], a[i]);
        }
        else
        {
            mx = max(mx * a[i], a[i]);
            mn = min(mn * a[i], a[i]);
        }
        tot = max(tot, mx);
    }
    return tot;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n;
        cin >> n;
        vi a(n);

        for (auto &r : a)
        {
            cin >> r;
        }
        cout << maxProduct(a);
    }
    return 0;
}