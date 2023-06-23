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

int solve(vector<int> &a, int key, int low, int high)
{
    if (low > high)
    {
        return INT_MAX;
    }
    if (high - low <= 1)
    {
        return min(a[high], a[low]);
    }
    int mid = (low + high) / 2;

    if (a[mid] < key)
    {
        return min(solve(a, key, low, mid - 1), a[mid]);
    }
    else
    {
        return min(solve(a, key, low, mid - 1), solve(a, a[mid], mid, high));
    }
    return INT_MIN;
}
int findMin(vector<int> &a)
{
    return solve(a, a[0], 0, a.size() - 1);
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
    }
    return 0;
}