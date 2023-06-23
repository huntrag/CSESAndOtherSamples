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

#define left(v) 2 * v + 1
#define right(v) 2 * v + 2

int sizeofsegmenttree(int n)
{
    int k = (int)ceil((double)log2(n));
    return 2 * pow(2, k) - 1;
}

void createSegment(vi &a, vi &t, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    createSegment(a, t, left(v), vl, vm);
    createSegment(a, t, right(v), vm + 1, vr);

    t[v] = t[left(v)] ^ t[right(v)];
}

int query(vi &t, int v, int vl, int vr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (vl == l && vr == r)
    {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    return (query(t, left(v), vl, vm, l, min(vm, r)) ^ query(t, right(v), vm + 1, vr, max(vm + 1, l), r));
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vi t(sizeofsegmenttree(n));

        createSegment(a, t, 0, 0, n - 1);

        while (q--)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << query(t, 0, 0, n - 1, x, y) << "\n";
        }
    }
    return 0;
}