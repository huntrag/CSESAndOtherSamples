#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e6 + 2;
ll arr[N] = {0};
ll segTree[4 * N] = {0};
ll lazy[4 * N] = {0};

void build(ll i, ll l, ll r)
{
    if (l == r)
    {
        segTree[i] = arr[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid + 1, r);
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}

void update(ll i, ll ss, ll se, ll qs, ll qe, ll val)
{
    if (lazy[i] != 0)
    {
        segTree[i] += lazy[i];
        if (ss != se)
        {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return;

    if (ss >= qs && se <= qe)
    {
        segTree[i] += val;
        if (ss != se)
        {
            lazy[2 * i + 1] += val;
            lazy[2 * i + 2] += val;
        }
        return;
    }
    ll mid = ss + (se - ss) / 2;
    update(2 * i + 1, ss, mid, qs, qe, val);
    update(2 * i + 2, mid + 1, se, qs, qe, val);
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}

ll getMin(ll i, ll ss, ll se, ll qs, ll qe)
{
    if (lazy[i] != 0)
    {
        segTree[i] += lazy[i];
        if (ss != se)
        {
            lazy[2 * i + 1] += lazy[i];
            lazy[2 * i + 2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return LLONG_MIN;

    if (ss >= qs && se <= qe)
        return segTree[i];

    ll mid = ss + (se - ss) / 2;
    ll left = getMin(2 * i + 1, ss, mid, qs, qe);
    ll right = getMin(2 * i + 2, mid + 1, se, qs, qe);
    return max(left, right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    ll a[n];
    cin >> a[0];
    arr[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        cin >> a[i];
        arr[i] = arr[i - 1] + a[i];
    }

    build(0, 0, n - 1);
    while (q--)
    {
        ll x;
        ll l, r;
        cin >> x >> l >> r;
        if (x == 2)
        {
            cout << getMin(0, 0, n - 1, l - 1, r - 1) << endl;
        }
        else
        {
            ll val = r - a[l - 1];
            a[l - 1] = r;
            update(0, 0, n - 1, l - 1, n - 1, val);
        }
    }

    return 0;
}