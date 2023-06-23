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

#define indexset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// indexset ist;
// ist.insert(5);
// ist.insert(4);
// ist.insert(7);
// cout << *(ist.find_by_order(0));
// cout << "\n"
//      << (ist.order_of_key(5));

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        indexset ist;
        ist.insert(5);
        ist.insert(4);
        ist.insert(7);
        cout << *(ist.find_by_order(0));
        cout << "\n"
             << (ist.order_of_key(5));
    }
    return 0;
}