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

vi singleNumber(vi &a)
{
    int pairxy = 0;
    for (auto &r : a)
    {
        pairxy = (pairxy ^ r);
    }

    // find last bit where x and y differ
    int lastBit = (pairxy & (-pairxy));
    int x = 0, y = 0;
    for (auto &r : a)
    {
        if ((r & lastBit) == 0)
        {
            x = (x ^ r);
        }
        else
        {
            y = (y ^ r);
        }
    }
    return vi({x, y});
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
        vi ans = singleNumber(a);
        cout << ans[0] << " " << ans[1];
    }
    return 0;
}