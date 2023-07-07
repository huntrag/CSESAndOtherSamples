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

int maxProfitbetter(int k, vector<int> &prices)
{
    int n = (int)prices.size();
    int ret = 0, v, p = 0;
    priority_queue<int> profits;
    stack<pair<int, int>> vp_pairs;
    while (p < n)
    {
        // find next valley/peak pair
        for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; v++)
            ;
        for (p = v + 1; p < n && prices[p] >= prices[p - 1]; p++)
            ;
        // save profit of 1 transaction at last v/p pair, if current v is lower than last v
        while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first])
        {
            profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        // save profit difference between 1 transaction (last v and current p) and 2 transactions (last v/p + current v/p),
        // if current v is higher than last v and current p is higher than last p
        while (!vp_pairs.empty() && prices[p - 1] >= prices[vp_pairs.top().second - 1])
        {
            profits.push(prices[vp_pairs.top().second - 1] - prices[v]);
            v = vp_pairs.top().first;
            vp_pairs.pop();
        }
        vp_pairs.push(pair<int, int>(v, p));
    }
    // save profits of the rest v/p pairs
    while (!vp_pairs.empty())
    {
        profits.push(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
        vp_pairs.pop();
    }
    // sum up first k highest profits
    for (int i = 0; i < k && !profits.empty(); i++)
    {
        ret += profits.top();
        profits.pop();
    }
    return ret;
}

int maxProfit(int k, vector<int> &a)
{
    int n = a.size();
    vvi dp1(n, vi(n));
    vvi dp2(k + 1, vi(n));
    int mn;
    for (int i = 0; i < n; i++)
    {
        mn = a[i];
        for (int j = i + 1; j < n; j++)
        {
            dp1[i][j] = dp1[i][j - 1];
            if (a[j] < mn)
            {
                mn = a[j];
            }
            else
            {
                dp1[i][j] = max(dp1[i][j], a[j] - mn);
            }
        }
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < j; l++)
            {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][l] + dp1[l][j]);
            }
        }
    }

    return dp2[k][n - 1];
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
        cout << maxProfit(k, a);
    }
    return 0;
}