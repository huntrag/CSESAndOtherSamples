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

    if (n <= 3 && n > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " ";
    }

    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " ";
    }

    return 0;
}