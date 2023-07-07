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
int upto(int x)
{
    if (x == 31)
    {
        return 0;
    }
    int z = (1 << x) - 1;
    return (INT_MAX ^ z);
}

int rangeBitwiseAnd(int left, int right)
{
    vector<int> uptom(32);

    for (int i = 0; i < 32; i++)
    {
        uptom[i] = upto(i);
    }

    int mask = 1;
    int prev;
    int ans = 0;
    for (int i = 0; i < 31; i++)
    {
        mask = (1 << i);
        if ((left & mask) && (right & mask))
        {
            prev = (left & uptom[i]);
            if (right - prev < mask)
            {
                ans = ans | mask;
            }
        }
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
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