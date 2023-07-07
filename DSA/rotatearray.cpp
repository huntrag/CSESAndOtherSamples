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

void rotate(vector<int> &a, int k)
{
    int n = a.size();
    k = k % n;
    if (k == 0)
    {
        return;
    }
    int i;
    for (i = 0; i < k && i < n - k; i++)
    {
        swap(a[i], a[n - k + i]);
    }
    if (i == k)
    {
        reverse(a.begin() + i, a.begin() + n - k);
        reverse(a.begin() + n - k, a.end());
        reverse(a.begin() + i, a.end());
    }
    else
    {
        reverse(a.begin() + n - k, a.begin() + n - k + i);
        reverse(a.begin() + n - k + i, a.end());
        reverse(a.begin() + n - k, a.end());
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
    }
    return 0;
}