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

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return false;
}

int findLongestChain(vector<vector<int>> &pairs)
{
    int n = pairs.size();
    vector<pair<int, int>> a(pairs.size());

    for (int i = 0; i < n; i++)
    {
        a[i] = make_pair(pairs[i][0], pairs[i][1]);
    }

    sort(a.begin(), a.end(), comp);

    int count = 1;
    int mx = a[0].second;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first > mx)
        {
            mx = a[i].second;
            count++;
        }
    }
    return count;
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

        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            cin >> a[i][0] >> a[i][1];
        }

        cout << findLongestChain(a);
    }
    return 0;
}