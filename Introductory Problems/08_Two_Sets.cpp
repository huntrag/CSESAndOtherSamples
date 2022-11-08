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

    if (n % 4 == 3 || n % 4 == 0)
    {
        cout << "YES\n";
        vector<int> a(ceil((double)n / 2)), b(n / 2);
        int ia = 0, ib = 0, i = 1;
        if (n % 4 == 3)
        {
            a[ia++] = 1;
            a[ia++] = 2;
            b[ib++] = 3;
            i = 4;
        }

        for (; i <= n; i++)
        {
            if ((n % 4 == 0 && (i % 4 == 1 || i % 4 == 0)) ||
                (n % 4 == 3) && (i % 4 == 0 || i % 4 == 3))
            {
                a[ia++] = i;
            }
            else
            {
                b[ib++] = i;
            }
        }
        cout << a.size() << "\n";
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n"
             << b.size() << "\n";
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}