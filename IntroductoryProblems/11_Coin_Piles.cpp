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
    int test;
    cin >> test;

    while (test--)
    {
        double a, b;
        cin >> a >> b;
        // a=2*m+n
        // 2b=4*n+2m
        // n=2b-a/3
        // m=2a-b/3
        double n = (double)(2 * b - a) / 3;
        double m = (double)(2 * a - b) / 3;
        if (n >= 0 && m >= 0 && (ceil(n) - floor(n) == 0) && (ceil(m) - floor(m) == 0))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}