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
int countPrimes(int n)
{
    vector<bool> sieve(n + 1);

    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            continue;
        }
        for (int j = 2; i * j <= n; j++)
        {
            sieve[i * j] = true;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        count += (sieve[i] ^ 1);
    }

    return count;
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
    }
    return 0;
}