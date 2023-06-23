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
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    indexed_set s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int size = n;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int nth = ((k % size) + cur) % size;
        auto it = s.find_by_order(nth);
        cout << *it << " ";
        it++;
        if (it == s.end())
        {
            it == s.begin();
        }
        cur = s.order_of_key(*it);
        if (it == s.begin())
        {
            it = s.end();
        }
        it--;
        s.erase(it);
        size--;
        cur--;
        if (cur == -1)
        {
            cur = size;
        }
    }

    return 0;
}