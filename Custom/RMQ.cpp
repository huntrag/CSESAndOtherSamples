#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<ll, ll> pll;
#define MOD 1000000007
#define fi first
#define se second

int left(int v)
{
    return (2 * v + 1);
}

int right(int v) { return 2 * v + 2; }

void createSegmentUtil(vpll &t, vll &a, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v].first = a[vl];
        t[v].second = vl;
        // cout << vl << " " << a[vl] << "\n";
        return;
    }
    int tm = (vl + vr) / 2;
    createSegmentUtil(t, a, left(v), vl, tm);
    createSegmentUtil(t, a, right(v), tm + 1, vr);

    if (t[left(v)].first < t[right(v)].first)
    {
        t[v] = t[left(v)];
    }
    else
    {
        t[v] = t[right(v)];
    }
}

pll getRangeUtil(vpll &t, int v, int vl, int vr, int l, int r)
{
    if (l > r)
    {
        return make_pair(LLONG_MAX, -1);
    }
    if (l == vl && r == vr)
    {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    pll lft = getRangeUtil(t, left(v), vl, vm, l, min(r, vm));
    pll rght = getRangeUtil(t, right(v), vm + 1, vr, max(vm + 1, l), r);

    if (lft.first < rght.first)
    {
        return lft;
    }
    else
    {
        return rght;
    }
}

void setPosUtil(vpll &t, int v, int vl, int vr, int pos, int new_val)
{
    if (vl == vr)
    {
        t[v].first = new_val;
    }
    else
    {
        int vm = (vl + vr) / 2;

        if (pos <= vm)
        {
            setPosUtil(t, left(v), vl, vm, pos, new_val);
        }
        else
        {
            setPosUtil(t, right(v), vm + 1, vr, pos, new_val);
        }
        if (t[left(v)].first < t[right(v)].first)
        {
            t[v] = t[left(v)];
        }
        else
        {
            t[v] = t[right(v)];
        }
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
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vll a(n);
        for (auto &x : a)
        {
            cin >> x;
        }

        vpll t(4 * n);

        createSegmentUtil(t, a, 0, 0, n - 1);

        for (int i = 0; i < n; i++)
        {

            if (i + k >= n)
            {
                continue;
            }
            // cout << i + k << "\n";
            pll val = getRangeUtil(t, 0, 0, n - 1, i + k, n - 1);
            if (val.first < a[i])
            {
                setPosUtil(t, 0, 0, n - 1, val.second, a[i]);
                setPosUtil(t, 0, 0, n - 1, i, val.first);
                swap(a[val.second], a[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}