#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second
#define MAX 100001

#define left(v) 2 * v + 1
#define right(v) 2 * v + 2

bool comp(pii &a, pii &b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return false;
}

void create(vi &t, vi &a, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v] = a[vl];
        return;
    }

    int vm = (vl + vr) / 2;
    create(t, a, left(v), vl, vm);
    create(t, a, right(v), vm + 1, vr);

    t[v] = max(t[left(v)], t[right(v)]);
}

int searchRange(vi &t, int v, int vl, int vr, int l, int r)
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
    return max(searchRange(t, left(v), vl, vm, l, min(vm, r)),
               searchRange(t, right(v), vm + 1, vr, max(vm + 1, l), r));
}

void update(vi &t, int v, int vl, int vr, int pos, int val)
{
    if (vl == vr && vl == pos)
    {
        t[v] = val;
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos <= vm)
    {
        update(t, left(v), vl, vm, pos, val);
    }
    else
    {
        update(t, right(v), vm + 1, vr, pos, val);
    }

    t[v] = max(t[left(v)], t[right(v)]);
}

void printSegmentTree(vector<int> &t, int n)
{
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, n - 1)));

    int v, vl, vr, vm;

    while (!q.empty())
    {
        v = q.front().first;
        vl = q.front().second.first;
        vr = q.front().second.second;
        vm = (vl + vr) / 2;

        cout << "V " << v << " - ( " << vl << ", " << vr << " ) - " << t[v] << "\n";
        q.pop();
        if (vl == vr)
        {
            continue;
        }
        q.push(make_pair(left(v), make_pair(vl, vm)));
        q.push(make_pair(right(v), make_pair(vm + 1, vr)));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vi arr1(n);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        vi t(4 * MAX, 0);

        // create(t, arr1, 0, 0, n - 1);
        int x;
        for (int i = 0; i < n; i++)
        {
            x = searchRange(t, 0, 0, MAX - 1, max(0, arr1[i] - k), arr1[i] - 1);
            update(t, 0, 0, MAX - 1, arr1[i], x + 1);
        }

        // printSegmentTree(t, MAX);
        cout << t[0];
    }
    return 0;
}