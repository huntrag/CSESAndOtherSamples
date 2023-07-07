// using binary search and RMaxQ with index segment tree
// second approach uses priority queue

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

typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

void create(vpi &t, vi &a, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v].first = a[vl];
        t[v].second = vl;
        return;
    }
    int mid = (vl + vr) / 2;
    create(t, a, left(v), vl, mid);
    create(t, a, right(v), mid + 1, vr);
    if (t[left(v)].first > t[right(v)].first)
    {
        t[v] = t[left(v)];
    }
    else
    {
        t[v] = t[right(v)];
    }
}

pair<int, int> get(vpi &t, int v, int vl, int vr, int l, int r)
{
    if (l > r)
    {
        return make_pair(INT_MIN, -1);
    }
    if (vl == l && vr == r)
    {
        return t[v];
    }
    int mid = (vl + vr) / 2;
    pair<int, int> lft = get(t, left(v), vl, mid, l, min(mid, r)), rght = get(t, right(v), mid + 1, vr, max(mid + 1, l), r);
    if (lft.first > rght.first)
    {
        return lft;
    }

    return rght;
}

void put(vpi &t, int v, int vl, int vr, int pos, int val)
{
    if (vl == vr && vl == pos)
    {
        t[v].first = val;
        return;
    }
    int mid = (vl + vr) / 2;
    if (pos <= mid)
    {
        put(t, left(v), vl, mid, pos, val);
    }
    else
    {
        put(t, right(v), mid + 1, vr, pos, val);
    }
    if (t[left(v)].first > t[right(v)].first)
    {
        t[v] = t[left(v)];
    }
    else
    {
        t[v] = t[right(v)];
    }
}

int findMaximizedCapital(int k, int w, vector<int> &pro, vector<int> &cap)
{
    int n = pro.size();
    vector<pair<int, int>> pr(n);

    for (int i = 0; i < n; i++)
    {
        pr[i] = make_pair(cap[i], pro[i]);
    }

    sort(pr.begin(), pr.end());

    for (int i = 0; i < n; i++)
    {
        cap[i] = pr[i].first;
        pro[i] = pr[i].second;
    }
    vector<pair<int, int>> t(4 * n);
    create(t, pro, 0, 0, n - 1);

    while (k--)
    {
        int ind = upper_bound(cap.begin(), cap.end(), w) - cap.begin() - 1;
        if (ind == -1)
        {
            break;
        }
        pair<int, int> mx = get(t, 0, 0, n - 1, 0, ind);

        if (mx.first == INT_MIN)
        {
            break;
        }

        w = w + mx.first;
        put(t, 0, 0, n - 1, mx.second, INT_MIN);
    }
    return w;
}

// priority queue
int findMaximizedCapital2(int k, int w, vector<int> &pro, vector<int> &cap)
{
    int n = pro.size();
    vector<pair<int, int>> pr(n);

    for (int i = 0; i < n; i++)
    {
        pr[i] = make_pair(cap[i], pro[i]);
    }

    sort(pr.begin(), pr.end());

    for (int i = 0; i < n; i++)
    {
        cap[i] = pr[i].first;
        pro[i] = pr[i].second;
    }

    priority_queue<int, vector<int>> pq;
    int i = 0;
    while (k--)
    {
        while (i < n && cap[i] <= w)
        {
            pq.push(pro[i]);
            i++;
        }
        if (pq.empty())
        {
            break;
        }
        w = w + pq.top();
        pq.pop();
    }
    return w;
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
    // cin>>test;
    while (test--)
    {
    }
    return 0;
}