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

int minPatches(vi &a, int k)
{
    int n = a.size();

    multiset<int> ms;

    for (auto &x : a)
    {
        ms.insert(x);
    }

    vi factors;
    int cur = k;
    while (cur > 0)
    {
        factors.push_back(cur);
        cur = (cur + 1) / 2;
    }
    reverse(factors.begin(), factors.end());

    for (int i = 0; i < factors.size(); i++)
    {
    }
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
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (auto &x : a)
        {
            cin >> x;
        }
        cout << minPatches(a, k);
    }
    return 0;
}