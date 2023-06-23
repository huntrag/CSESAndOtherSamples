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

    vector<ll> fenwick = createFenwick(a);
    cout << sumRange(fenwick, 0, 2) << "\n";
    pointUpdate(fenwick, 1, -1);
    cout << sumRange(fenwick, 1, 2) << "\n";

    return 0;
}