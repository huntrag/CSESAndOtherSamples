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
// int the above if only less than it would be set
struct arr
{
    int fi;
    int se;
    int ind;
};

bool comp1(arr a, arr b)
{
    if (a.fi < b.fi)
    {
        return true;
    }
    else if (a.fi == b.fi)
    {
        return a.se > b.se;
    }
    return false;
}

bool comp2(arr a, arr b)
{
    if (a.se < b.se)
    {
        return true;
    }
    else if (a.se == b.se)
    {
        return a.fi > b.fi;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<arr> a(n);
    vector<vector<int>> ans(2, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].fi = x;
        a[i].se = y;
        a[i].ind = i;
    }

    sort(a.begin(), a.end(), comp1);

    indexed_set s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i].se);
    }

    for (int i = 0; i < n; i++)
    {
        int ord = s.order_of_key(a[i].se + 1);
        ans[0][a[i].ind] = ord - 1;
        s.erase(s.find_by_order(ord - 1));
    }
    s.clear();
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i].fi);
    }
    sort(a.begin(), a.end(), comp2);
    for (int i = 0; i < n; i++)
    {
        int ord = s.order_of_key(a[i].fi + 1);
        ans[1][a[i].ind] = ord - 1;
        s.erase(s.find_by_order(ord - 1));
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}