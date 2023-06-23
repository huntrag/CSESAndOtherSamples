#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        vll a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vll prefix(n + 1);
        prefix[0] = 0;

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + a[i];
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << prefix[r + 1] - prefix[l] << "\n";
        }
    }
    return 0;
}