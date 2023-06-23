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

ll sizeofsegmenttree(ll n)
{
    ll k = (ll)ceil((double)log2(n));
    return 2 * pow(2, k) - 1;
}

void construct(vll &t, vll &a, ll v, ll vl, ll vr)
{
    if (vl == vr)
    {
        t[v] = a[vl];
        return;
    }
    ll vm = (vl + vr) / 2;
    construct(t, a, left(v), vl, vm);
    construct(t, a, right(v), vm + 1, vr);
    t[v] = t[left(v)] + t[right(v)];
}

void update(vll &t, vll &lazy, ll v, ll vl, ll vr, ll l, ll r, ll diff)
{
    if (lazy[v] != 0)
    {
        t[v] += (vr - vl + 1) * lazy[v];

        if (vl != vr)
        {
            lazy[left(v)] += lazy[v];
            lazy[right(v)] += lazy[v];
        }

        lazy[v] = 0;
    }

    if (vl > vr || r < vl || vr < l)
    {
        return;
    }

    if (l <= vl && r >= vr)
    {
        t[v] += (vr - vl + 1) * diff;

        if (vl != vr)
        {
            lazy[left(v)] += diff;
            lazy[right(v)] += diff;
        }

        return;
    }

    ll vm = (vl + vr) / 2;
    update(t, lazy, left(v), vl, vm, l, r, diff);
    update(t, lazy, right(v), vm + 1, vr, l, r, diff);

    t[v] = t[left(v)] + t[right(v)];
}

ll query(vll &t, vll &lazy, ll v, ll vl, ll vr, ll l, ll r)
{
    if (lazy[v] != 0)
    {
        t[v] += (vr - vl + 1) * lazy[v];

        if (vl != vr)
        {
            lazy[left(v)] += lazy[v];
            lazy[right(v)] += lazy[v];
        }

        lazy[v] = 0;
    }

    if (vl > vr || r < vl || vr < l)
    {
        return 0;
    }

    if (l <= vl && r >= vr)
    {
        return t[v];
    }

    ll vm = (vl + vr) / 2;

    return query(t, lazy, left(v), vl, vm, l, r) +
           query(t, lazy, right(v), vm + 1, vr, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {
        ll n, q;
        cin >> n >> q;
        vll a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> t(sizeofsegmenttree(n), 0);
        vector<ll> lazy(t.size(), 0);

        construct(t, a, 0, 0, n - 1);

        while (q--)
        {
            ll type;
            cin >> type;

            if (type == 1)
            {
                ll l, r, diff;
                cin >> l >> r >> diff;
                l--;
                r--;
                update(t, lazy, 0, 0, n - 1, l, r, diff);
            }
            else
            {
                int pos;
                cin >> pos;
                pos--;
                cout << query(t, lazy, 0, 0, n - 1, pos, pos) << "\n";
            }
        }
    }
    return 0;
}