// sqrt decomposition method
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

void createSqrtDecom(vll &decom, vll &a, int n)
{
    int s = decom.size();

    for (int i = 0; i < n; i++)
    {
        decom[i / s] = min(decom[i / s], a[i]);
    }
}

ll query(vll &decom, vll &a, int l, int r)
{
    ll mn = LLONG_MAX;
    int s = decom.size();
    int c_l = l / s, c_r = r / s;
    if (c_l == c_r)
        for (int i = l; i <= r; i++)
            mn = min(mn, a[i]);
    else
    {
        for (int i = l, end = (c_l + 1) * s - 1; i <= end; i++)
            mn = min(mn, a[i]);
        for (int i = c_l + 1; i <= c_r - 1; i++)
            mn = min(mn, decom[i]);
        for (int i = c_r * s; i <= r; i++)
            mn = min(mn, a[i]);
    }

    return mn;
}

void update(vll &decom, vll &a, int ind)
{
    int s = decom.size();
    int block = ind / s;
    int block_start = block * s;
    int block_end = min((int)a.size() - 1, (int)(block + 1) * s - 1);
    decom[block] = LLONG_MAX;
    for (int i = block_start; i <= block_end; i++)
    {
        decom[block] = min(decom[block], a[i]);
    }
}

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

        int s = sqrt(n + 0.1) + 1;

        vll decom(s, MOD);

        createSqrtDecom(decom, a, n);

        while (q--)
        {
            ll t, l, r;
            cin >> t >> l >> r;
            if (t == 1)
            {
                a[l - 1] = r;
                update(decom, a, l - 1);
                continue;
            }

            l--;
            r--;
            cout << query(decom, a, l, r) << "\n";
        }
    }
    return 0;
}