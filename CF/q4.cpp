#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
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
    cin >> test;
    while (test--)
    {
        ld n, d, h;
        cin >> n >> d >> h;
        vld a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ld hlf = (ld)0.5;

        ld area = (ld)hlf * d * h;

        for (int i = 0; i < n - 1; i++)
        {
            if ((ld)0.000001 < a[i] + h - a[i + 1])
            {
                ld x = a[i] + h - a[i + 1];
                area = (ld)area + (hlf * (((x * d) / h) + d) * (h - x));
            }
            else
            {
                area = (ld)area + (ld)hlf * d * h;
            }
        }
        cout << fixed << setprecision(7) << area << "\n";
    }
    return 0;
}