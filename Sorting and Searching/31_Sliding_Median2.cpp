#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

void balance(multiset<ll> &left, multiset<ll> &right, int k)
{
    int left_size = ceil((ld)k / 2), right_size = k / 2;
    while (left.size() < left_size)
    {
        auto it = right.begin();
        left.insert(*it);
        right.erase(right.find(*it));
    }
    while (right.size() < right_size)
    {
        auto it = left.rbegin();
        right.insert(*it);
        left.erase(left.find(*it));
    }
    while ((*right.begin()) < (*left.rbegin()))
    {
        auto leftOne = left.rbegin();
        auto rightOne = right.begin();
        right.insert(*leftOne);
        left.insert(*rightOne);
        right.erase(right.find(*rightOne));
        left.erase(left.find(*leftOne));
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
            cout << a[i] << " ";
        }
    }
    else if (k == 2)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << min(a[i], a[i + 1]) << " ";
        }
    }
    else
    {
        multiset<ll> left, right;
        for (int i = 0; i < k; i++)
        {
            left.insert(a[i]);
        }
        balance(left, right, k);
        for (int i = k; i < n; i++)
        {
            auto it = left.rbegin();
            cout << *it << " ";
            if (left.find(a[i - k]) == left.end())
            {
                right.erase(right.find(a[i - k]));
            }
            else
            {
                left.erase(left.find(a[i - k]));
            }
            if (a[i] > *it)
            {
                right.insert(a[i]);
            }
            else
            {
                left.insert(a[i]);
            }
            balance(left, right, k);
        }
        cout << *left.rbegin();
    }
    return 0;
}