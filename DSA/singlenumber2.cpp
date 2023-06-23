// One of the best problems i have ever seen
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

int singleNumber(vector<int> &nums)
{
    int b0 = 0, b1 = 0, mask = 0;
    // we are creating counters for 3 - 11 (b1,b0)
    for (auto &x : nums)
    {
        b1 = (b1 ^ (b0 & x));
        b0 = (b0 ^ x);
        mask = ~(b1 & b0);
        // as we want mask for 3
        // if we wanted for 2 it would be ~(b1 & (~b0))
        b0 = (b0 & mask);
        b1 = (b1 & mask);
    }
    return b1 | b0;
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
        int x;
        vi a;
        while (cin >> x)
        {
            a.push_back(x);
        }
        cout << singleNumber(a);
    }
    return 0;
}