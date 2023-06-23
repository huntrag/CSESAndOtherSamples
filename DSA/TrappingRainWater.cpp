#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

int trap(vector<int> &height)
{
    int n = height.size();

    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);
    prefixMax[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], height[i]);
    }
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    ll sum = 0;
    int mn;

    for (int i = 0; i < n; i++)
    {
        mn = min(prefixMax[i], suffixMax[i]);
        sum = (ll)sum + abs(mn - height[i]);
    }

    return sum;
}
// Test case 1 : 0 1 0 2 1 0 1 3 2 1 2 1
// Ans = 6

// Test case 2: 4 2 0 3 2 5
// Ans = 9

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        vector<int> h;
        int x;
        while (cin >> x)
        {
            h.push_back(x);
        }

        cout << trap(h);
    }
    return 0;
}