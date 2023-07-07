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
int eraseOverlapIntervals(vector<vector<int>> &iv)
{
    vector<pair<int, int>> a(iv.size());

    for (int i = 0; i < iv.size(); i++)
    {
        a[i] = make_pair(iv[i][1], iv[i][0]);
    }

    sort(a.begin(), a.end());

    int count = 0;
    int nd = a[0].first;

    for (int i = 1; i < iv.size(); i++)
    {
        if (a[i].second < nd)
        {
            count++;
        }
        else
        {
            nd = max(nd, a[i].first);
        }
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
    // cin>>test;
    while (test--)
    {
    }
    return 0;
}