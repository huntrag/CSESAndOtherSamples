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
#define MAX 1000000000000000000

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    ll x = 2;
    unordered_set<ll> us;
    while (true)
    {
        ll pw = x * x;
        ll init = 1 + x;
        init = init + pw;

        if (init >= MAX)
        {
            break;
        }
        ll sum = init;
        while (sum <= MAX)
        {
            us.insert(sum);
            pw = pw * x;
            sum = sum + pw;
        }
        x++;
    }

    while (test--)
    {
        ll x;
        cin >> x;
        if (us.find(x) == us.end())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}