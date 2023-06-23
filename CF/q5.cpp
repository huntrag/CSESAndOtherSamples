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
int leftpre(int v)
{
    return (v + 1);
}

int rightpre(int v, int l, int r) { return (v + 2 * (((l + r) / 2) - l + 1)); }

// #############################################

int left(int v) { return (2 * v); }

int right(int v) { return 2 * v + 1; }

// #############################################

void createSegmentUtil(vector<int> &t, vector<int> &a, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v] = a[vl];
        return;
    }
    int tm = (vl + vr) / 2;
    createSegmentUtil(t, a, 2 * v, vl, tm);
    createSegmentUtil(t, a, 2 * v + 1, tm + 1, vr);

    t[v] = t[v * 2] + t[v * 2 + 1];
}

vector<int> createSegmentTree(vector<int> &a)
{
    int n = a.size();
    vector<int> t(4 * n);
    createSegmentUtil(t, a, 1, 0, n - 1);

    return t;
}

int getRangeUtil(vector<int> &t, int v, int vl, int vr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (l == vl && r == vr)
    {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    return (getRangeUtil(t, 2 * v, vl, vm, l, min(r, vm)) +
            getRangeUtil(t, 2 * v + 1, vm + 1, vr, max(vm + 1, l), r));
}

int getRange(vector<int> &t, int l, int r)
{
    int n = t.size() / 4;
    return getRangeUtil(t, 1, 0, n - 1, l, r);
}

void printSegmentTree(vector<int> &t)
{
    queue<pair<int, pair<int, int>>> q;
    int n = t.size() / 4;
    q.push(make_pair(1, make_pair(0, n - 1)));

    int v, tl, tr, tm;

    while (!q.empty())
    {
        v = q.front().first;
        tl = q.front().second.first;
        tr = q.front().second.second;
        tm = (tl + tr) / 2;

        cout << "V " << v << " - ( " << tl << ", " << tr << " ) - " << t[v] << "\n";
        q.pop();
        if (tl == tr)
        {
            continue;
        }
        q.push(make_pair(2 * v, make_pair(tl, tm)));
        q.push(make_pair(2 * v + 1, make_pair(tm + 1, tr)));
    }
}

void setPosUtil(vector<int> &t, int v, int vl, int vr, int pos, int new_val)
{
    if (vl == vr)
    {
        t[v] = new_val;
    }
    else
    {
        int vm = (vl + vr) / 2;

        if (pos <= vm)
        {
            setPosUtil(t, 2 * v, vl, vm, pos, new_val);
        }
        else
        {
            setPosUtil(t, 2 * v + 1, vm + 1, vr, pos, new_val);
        }
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void setPos(vector<int> &t, int pos, int new_val)
{
    int n = t.size() / 4;
    setPosUtil(t, 1, 0, n - 1, pos, new_val);
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
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi t(4 * n, 0);
        set<pair<int, int>> st;
        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            st.insert(make_pair(x, y));
        }
        int q;
        cin >> q;
        vi q1(q);
        for (int i = 0; i < q; i++)
        {
            cin >> q1[i];
        }

        int i = 0;
        bool flag = false;
        for (i = 0; i < q; i++)
        {
            int ind = q1[i];
            ind--;
            if (a[ind] == 1)
            {
                continue;
            }
            a[ind] = 1;
            setPos(t, ind, 1);
            for (auto &u : st)
            {
                int l = u.first;
                int r = u.second;

                if (ind >= l && ind <= r)
                {

                    int tot = (r - l + 1);
                    int ans = getRange(t, l, r);
                    tot = tot - ans;
                    if (tot < ans)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << i + 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
