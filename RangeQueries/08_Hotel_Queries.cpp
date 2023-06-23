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

int query(int req, vi &d, vi &a)
{
    int grp;
    int sq = d.size();
    for (grp = 0; grp < sq; grp++)
    {
        if (d[grp] >= req)
        {
            break;
        }
    }
    if (grp == sq)
    {
        return 0;
    }

    int st = sq * grp;
    int end = (((grp + 1) * sq - 1) >= a.size()) ? (a.size() - 1) : (grp + 1) * sq - 1;
    int i;
    int ans = 0;
    for (i = st; i <= end; i++)
    {
        if (a[i] >= req)
        {
            ans = i + 1;
            a[i] = a[i] - req;
            break;
        }
    }
    d[grp] = 0;
    for (int i = st; i <= end; i++)
    {
        d[grp] = max(d[grp], a[i]);
    }

    return ans;
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
        vi a(n);
        int sq = ceil(sqrt(n) + 0.1);
        vi d(sq, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            d[i / sq] = max(d[i / sq], a[i]);
        }

        while (q--)
        {
            ll req;
            cin >> req;
            cout << query(req, d, a) << " ";
        }
    }
    return 0;
}
