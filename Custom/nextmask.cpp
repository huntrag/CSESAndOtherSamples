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
int mask = 3;

void nextmask(vi &a)
{
    vi prev(a);

    int nd = prev[0];

    a[0] = (prev[0] + 1) % mask;

    for (int i = 1; i < a.size(); i++)
    {
        a[i] = (prev[i] + (nd & 2) / 2) % mask;
        nd = (nd & prev[i]);
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
    cin >> test;
    while (test--)
    {
    }
    return 0;
}