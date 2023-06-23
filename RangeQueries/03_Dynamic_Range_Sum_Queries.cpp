// Fenwick Tree one based indexing
// there are two types of g(i) represtation
// one for one based indexing and other for zero based indexing

// g(i)=i&(i+1) for zero based indexing
// g(i)=i&(-i) for one based indexing

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

// (x&(-x)) returns lsb

ll operation(ll x, ll y)
{
    return (ll)x + y;
}

vector<ll> createFenwick(vector<ll> &arr)
{
    int n = arr.size() - 1;
    vector<ll> fenwick(n + 1, 0);
    int j;
    for (int i = 1; i <= n; i++)
    {
        j = i + (i & (-i));
        fenwick[i] = operation(fenwick[i], arr[i]);
        if (j <= n)
        {
            fenwick[j] = operation(fenwick[j], fenwick[i]);
        }
    }
    return fenwick;
}

void pointUpdate(vector<ll> &fenwick, int ind, int val)
{
    int i = ind, n = fenwick.size();
    while (i < n)
    {
        fenwick[i] = operation(fenwick[i], val);
        i = i + (i & (-i));
    }
}

ll pointQuery(vector<ll> &fenwick, int ind)
{
    ll tot = 0;
    int i = ind;
    while (i > 0)
    {
        tot = operation(tot, fenwick[i]);
        i = i - (i & (-i));
    }

    return tot;
}

ll rangeQuery(vector<ll> &fenwick, int start, int end)
{
    return pointQuery(fenwick, end) - pointQuery(fenwick, start - 1);
}

void printFenwick(vector<ll> &fenwick)
{
    for (int i = 1; i < fenwick.size(); i++)
    {
        cout << fenwick[i] << " ";
    }
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // Fenwick tree is one based index as the original array

    vector<ll> fenwick = createFenwick(arr);
    // printFenwick(fenwick);

    while (q--)
    {
        ll t, k, u;
        cin >> t >> k >> u;

        if (t == 1)
        {
            pointUpdate(fenwick, k, (ll)u - arr[k]);
            arr[k] = u;
        }
        else
        {
            cout << rangeQuery(fenwick, k, u) << "\n";
        }
    }

    return 0;
}