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

void solve(vll &m, vi &a)
{
    int n = a.size();

    int tot = (1 << n);

    for (int bit = 0; bit < tot; bit++)
    {
        ll sum = 0;
        int msk = 1;
        for (int i = 0; i < n; i++)
        {
            if ((bit & msk))
            {
                sum = (ll)sum + a[i];
            }
            msk = msk * 2;
        }
        m.push_back(sum);
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
        int n, x;
        cin >> n >> x;
        vi a(n);
        for (auto &r : a)
        {
            cin >> r;
        }

        vi a1(n / 2);
        vi a2(n - a1.size());

        for (int i = 0; i < a1.size(); i++)
        {
            a1[i] = a[i];
        }
        for (int i = a1.size(); i < a1.size() + a2.size(); i++)
        {
            a2[i - a1.size()] = a[i];
        }
        ll tot = 0;
        vll m1, m2;
        solve(m1, a1);
        solve(m2, a2);
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
        for (auto &r : m1)
        {
            int ih = upper_bound(m2.begin(), m2.end(), x - r) - m2.begin();
            int il = lower_bound(m2.begin(), m2.end(), x - r) - m2.begin();

            tot += (ih - il);
        }
        cout << tot;
    }
    return 0;
}