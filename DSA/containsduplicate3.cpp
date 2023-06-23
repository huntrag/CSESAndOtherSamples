// used indexed set

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define indexset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//
// ist.insert(5);
// ist.insert(4);
// ist.insert(7);
// cout << *(ist.find_by_order(0));
//      << (ist.order_of_key(5));

bool containsNearbyAlmostDuplicate(vector<int> &a, int indexDiff, int valueDiff)
{
    int window = indexDiff + 1;
    indexset ist;
    int n = a.size();
    for (int i = 0; i < n && i < window; i++)
    {
        ist.insert(a[i]);
    }
    int i = 0;
    while (i < n)
    {
        int ind = ist.order_of_key(a[i]);
        if (ind != 0)
        {
            int prev = *(ist.find_by_order(ind - 1));
            if (abs(a[i] - prev) <= valueDiff)
            {
                return true;
            }
        }
        if (ind != ist.size() - 1)
        {
            int nxt = *(ist.find_by_order(ind + 1));
            if (abs(a[i] - nxt) <= valueDiff)
            {
                return true;
            }
        }
        ist.erase(ist.find_by_order(ind));

        if (i + window < n)
        {
            ist.insert(a[i + window]);
        }
        i++;
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    while (test--)
    {
        int n, index, value;
        cin >> n >> index >> value;
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << containsNearbyAlmostDuplicate(a, index, value);
    }
    return 0;
}