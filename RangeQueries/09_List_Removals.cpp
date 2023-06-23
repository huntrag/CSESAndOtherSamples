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

void create(vi &t, vi &a, int v, int vl, int vr)
{
    if (vl == vr)
    {
        if (a[vl] > 0)
        {
            t[v] = 1;
        }
        return;
    }
    create(t, a, left(v), vl, (vl + vr) / 2);
    create(t, a, right(v), (vl + vr) / 2 + 1, vr);

    t[v] = t[right(v)] + t[left(v)];
}

int query(vi &t, int v, int vl, int vr, int val)
{
    if (val > t[v])
    {
        return -1;
    }
    if (vl == vr)
    {
        return vl;
    }
    int vm = (vl + vr) / 2;
    if (t[left(v)] >= val)
    {
        return query(t, left(v), vl, vm, val);
    }
    else
    {
        return query(t, right(v), vm + 1, vr, val - t[left(v)]);
    }
}

void update(vi &t, int v, int vl, int vr, int pos)
{
    if (vl > vr)
    {
        return;
    }
    if (vl == vr && vl == pos)
    {
        t[v]--;
        return;
    }

    int vm = (vl + vr) / 2;

    if (pos <= vm)
    {
        update(t, left(v), vl, vm, pos);
    }
    else
    {
        update(t, right(v), vm + 1, vr, pos);
    }

    t[v] = t[left(v)] + t[right(v)];
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
        int n;
        cin >> n;
        vi l(n, 1);
        vi a(n);
        vi t(sizeofsegmenttree(n), 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        create(t, l, 0, 0, n - 1);
        int pos;
        for (int i = 0; i < n; i++)
        {
            cin >> pos;
            int ind = query(t, 0, 0, n - 1, pos);
            cout << a[ind] << " ";
            update(t, 0, 0, n - 1, ind);
        }
    }
    return 0;
}