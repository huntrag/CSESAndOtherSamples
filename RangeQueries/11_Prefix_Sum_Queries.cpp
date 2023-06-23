#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define sum first
#define pref second
#define left(v) 2 * v + 1
#define right(v) 2 * v + 2

vll a;
vpll t;

void construct(ll v, ll vl, ll vr)
{
    if (vl == vr)
    {
        t[v].sum = a[vl];
        t[v].pref = a[vl];
        return;
    }
    ll vm = (vl + vr) / 2;

    construct(left(v), vl, vm);
    construct(right(v), vm + 1, vr);

    t[v].sum = t[left(v)].sum + t[right(v)].sum;
    t[v].pref = max(t[left(v)].pref, t[right(v)].pref + t[left(v)].sum);
}

void update(ll v, ll vl, ll vr, ll pos, ll val)
{
    if (vl > vr)
    {
        return;
    }
    if (vl == vr && vl == pos)
    {
        t[v].sum = val;
        t[v].pref = val;
        return;
    }

    ll vm = (vl + vr) / 2;
    if (pos <= vm)
    {
        update(left(v), vl, vm, pos, val);
    }
    else
    {
        update(right(v), vm + 1, vr, pos, val);
    }
    t[v].sum = t[left(v)].sum + t[right(v)].sum;
    t[v].pref = max(t[left(v)].pref, t[right(v)].pref + t[left(v)].sum);
}

ll querysum(ll v, ll vl, ll vr, ll ql, ll qr)
{
    if (ql > qr)
    {
        return 0;
    }

    if (vl == ql && vr == qr)
    {
        return t[v].sum;
    }
    ll vm = (vl + vr) / 2;

    return (querysum(left(v), vl, vm, ql, min(qr, vm)) +
            querysum(right(v), vm + 1, vr, max(vm + 1, ql), qr));
}

ll query(ll v, ll vl, ll vr, ll ql, ll qr)
{
    if (ql > qr)
    {
        return 0;
    }

    if (vl == ql && vr == qr)
    {
        return t[v].pref;
    }
    ll vm = (vl + vr) / 2;

    return max(query(left(v), vl, vm, ql, min(qr, vm)),
               query(right(v), vm + 1, vr, max(vm + 1, ql), qr));
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
        ll n, q;
        cin >> n >> q;
        a.resize(n);
        t.resize(4 * n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        construct(0, 0, n - 1);
        while (q--)
        {
            ll t;
            cin >> t;
            if (t == 1)
            {
                // update
                ll pos, val;
                cin >> pos >> val;
                update(0, 0, n - 1, pos - 1, val);
            }
            else
            {
                ll l, r;
                cin >> l >> r;
                cout << query(0, 0, n - 1, l - 1, r - 1) << "\n";
            }
        }
    }
    return 0;
}