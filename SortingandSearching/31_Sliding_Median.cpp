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
#define indexed_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

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
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    indexed_set s;
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }
    cout << *s.find_by_order((k - 1) / 2) << " ";
    int st = 0;
    for (int i = k; i < n; i++)
    {
        s.erase(s.find_by_order(s.order_of_key(a[st])));
        st++;
        s.insert(a[i]);
        cout << *s.find_by_order((k - 1) / 2) << " ";
    }
    return 0;
}