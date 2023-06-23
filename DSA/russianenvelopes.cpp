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

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    vector<int> width(4 * MAX), height(4 * MAX);
    int n = envelopes.size();
    for (int i = 0; i < n; i++)
    {
        int w = searchRange(width, 0, 0, MAX - 1, 0, envelopes[i][0] - 1);
        int h = searchRange(height, 0, 0, MAX - 1, 0, envelopes[i][1] - 1);
        w = min(w, h);

        update(width, 0, 0, MAX - 1, envelopes[i][0], w + 1);
        update(height, 0, 0, MAX - 1, envelopes[i][1], w + 1);
    }

    return min(width[0], height[0]);
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
        int n;
        cin >> n;
        vector<vector<int>> e(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            cin >> e[i][0] >> e[i][1];
        }

        cout << maxEnvelopes(e);
    }
    return 0;
}