#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second
#define mp(x, y) make_pair(int, int)
template <typename T>
using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void balance(multiset<ll> &left, multiset<ll> &right, ll &lsum, ll &rsum, ll &lsize, ll &rsize)
{
    while ((ll)left.size() < (ll)lsize)
    {
        auto it = right.begin();
        ll val = *it;
        left.insert(val);
        lsum += (ll)val;
        right.erase(right.find(val));
        rsum -= (ll)val;
    }
    while ((ll)right.size() < (ll)rsize)
    {
        auto it = left.rbegin();
        ll val = *it;
        right.insert(val);
        rsum += (ll)val;
        lsum -= (ll)val;
        left.erase(left.find(val));
    }
    while ((*left.rbegin()) > (*right.begin()))
    {
        ll l = *left.rbegin();
        ll r = *right.begin();
        left.insert(r);
        lsum += (ll)(r - l);
        right.insert(l);
        rsum += (ll)(l - r);
        left.erase(left.find(l));
        right.erase(right.find(r));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << ' ';
        }
    }
    else if (k == 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << abs(a[i] - a[i + 1]) << " ";
        }
    }
    else
    {
        multiset<ll> left, right;
        ll lsum = 0ll, rsum = 0ll;
        ll lsize = ceil((ld)k / 2), rsize = k / 2;
        for (int i = 0; i < k; i++)
        {
            left.insert(a[i]);
            lsum += (ll)a[i];
        }
        ll bal = 0;

        balance(left, right, lsum, rsum, lsize, rsize);
        for (int i = k; i < n; i++)
        {
            auto it = left.rbegin();
            bal = (ll)(*it) * lsize - lsum + rsum - (*it) * rsize;
            cout << bal << " ";
            if (right.find(a[i - k]) == right.end())
            {
                left.erase(left.find(a[i - k]));
                lsum -= (ll)a[i - k];
            }
            else
            {
                right.erase(right.find(a[i - k]));
                rsum -= (ll)a[i - k];
            }
            if (a[i] > (*it))
            {
                right.insert(a[i]);
                rsum += (ll)a[i];
            }
            else
            {
                left.insert(a[i]);
                lsum += (ll)a[i];
            }
            balance(left, right, lsum, rsum, lsize, rsize);
        }
        auto it = left.rbegin();
        bal = (ll)(*it) * lsize - lsum + rsum - (*it) * rsize;
        cout << bal;
    }
    return 0;
}