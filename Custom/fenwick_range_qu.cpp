#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int g(int i)
{
    return (i & (i + 1));
}

int h(int i)
{
    return (i | (i + 1));
}

vector<ll> createFenwick(vector<ll> &a)
{
    int n = a.size();
    vector<ll> fenwick(n, 0);
    int j;
    for (int i = 0; i < n; i++)
    {
        j = h(i);
        fenwick[i] += a[i];
        if (j < n)
        {
            fenwick[j] += fenwick[i];
        }
    }

    return fenwick;
}

ll sumPoint(vector<ll> &fenwick, int ind)
{
    int n = fenwick.size();
    int i = ind;
    ll sum = 0;
    while (i >= 0)
    {
        sum += fenwick[i];
        i = g(i) - 1;
    }

    return sum;
}

ll sumRange(vector<ll> &fenwick, int start, int end)
{
    return sumPoint(fenwick, end) - sumPoint(fenwick, start - 1);
}

void pointUpdate(vector<ll> &fenwick, int ind, ll delta)
{
    int i = ind;
    int n = fenwick.size();
    while (i < n)
    {
        fenwick[i] += delta;
        i = h(i);
    }
}

void rangeUpdate(vector<ll> &fenwick1, vector<ll> &fenwick2, int l, int r, ll x)
{
    pointUpdate(fenwick1, l, x);
    pointUpdate(fenwick1, r + 1, -x);
    pointUpdate(fenwick2, l, (l - 1) * x);
    pointUpdate(fenwick2, r + 1, -x * r);
}

ll rangePointQuery(vector<ll> &fenwick1, vector<ll> &fenwick2, int ind)
{
    return sumPoint(fenwick1, ind) * ind - sumPoint(fenwick2, ind);
}

ll rangeQuery(vector<ll> &fenwick1, vector<ll> &fenwick2, int l, int r)
{
    return rangePointQuery(fenwick1, fenwick2, r) - rangePointQuery(fenwick1, fenwick2, l);
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
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // will work for empty array ig only

    vector<ll> fenwick1 = createFenwick(a);
    vector<ll> fenwick2 = createFenwick(a);
    cout << rangeQuery(fenwick1, fenwick2, 0, 4) << "\n";
    rangeUpdate(fenwick1, fenwick2, 1, 3, 2);
    cout << rangeQuery(fenwick1, fenwick2, 0, 4) << "\n";
    rangeUpdate(fenwick1, fenwick2, 3, 5, 5);
    cout << rangeQuery(fenwick1, fenwick2, 0, 4) << "\n";

    return 0;
}