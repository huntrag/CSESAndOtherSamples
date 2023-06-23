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

int jump(vector<int> &a)
{
    int count = 0;
    int mx = 0;
    int tot = 1;
    int n = a.size();
    count = a[0];
    if (n == 1)
    {
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            tot++;
            count = mx;
            mx = 0;
        }
        mx = max(mx, a[i] - count + 1);
        count--;
    }

    return tot;
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
    // cin >> test;
    while (test--)
    {
        vector<int> a;
        int x;
        while (cin >> x)
        {
            a.push_back(x);
        }

        cout << jump(a);
    }
    return 0;
}