#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define MOD 1000000007
#define fi first
#define se second
#define left(v) 2 * v + 1
#define right(v) 2 * v + 2

void createSegmentTreeUtil(vi &a, vi &t, int v, int vl, int vr)
{
    if (vl == vr)
    {
        t[v] = a[vr];
        return;
    }
    int vm = (vl + vr) / 2;
    createSegmentTreeUtil(a, t, left(v), vl, vm);
    createSegmentTreeUtil(a, t, right(v), vm + 1, vr);

    t[v] = min(t[left(v)], t[right(v)]);
}

vi createSegmentTree(vi &a)
{
    int n = a.size();
    int size = 2 * pow(2, log2(n)) - 1;
    vi t(size);

    createSegmentTreeUtil(a, t, 0, 0, n - 1);
    return t;
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
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vi t = createSegmentTree(a);
    printSegmentTree(t, n);

    int x = INT_MAX;
    int y = INT_MAX;

    return 0;
}