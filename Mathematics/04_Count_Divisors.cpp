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

int count(int x)
{
    int sq = sqrt(x);
    int cnt = 0;
    for (int i = 1; i <= sq; i++)
    {
        if (x % i == 0)
        {
            if (i == (x / i))
            {
                cnt++;
            }
            else
            {
                cnt += 2;
            }
        }
    }
    return cnt;
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
    cin >> test;
    while (test--)
    {
        int x;
        cin >> x;
        unordered_map<int, int> m;
        if (m.find(x) == m.end())
        {
            m[x] = count(x);
        }
        cout << m[x] << "\n";
    }
    return 0;
}