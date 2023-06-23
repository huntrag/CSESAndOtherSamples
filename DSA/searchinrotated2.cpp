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

bool part(vector<int> &a, int key, int flag, int low, int high)
{
    if (low > high)
    {
        return false;
    }
    else if (high - low <= 1)
    {
        return (a[low] == flag) | (a[high] == flag);
    }
    int mid = (low + high) / 2;

    if (a[mid] >= key)
    {
        return part(a, key, flag, low, mid - 1) | part(a, key, flag, mid, high);
    }
    else
    {
        return binary_search(a.begin() + mid, a.begin() + high + 1, flag) | part(a, key, flag, low, mid - 1);
    }
    return false;
}

bool search(vector<int> &a, int flag)
{
    return part(a, a[0], flag, 0, a.size() - 1);
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