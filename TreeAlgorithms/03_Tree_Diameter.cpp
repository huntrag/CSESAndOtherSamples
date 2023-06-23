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

class Tree
{
public:
    int n;
    vvi adj;
    vpii dp;
    vi ans;

    Tree(int x)
    {
        n = x;
        adj.resize(n);
        dp.resize(n);
        ans.resize(n);
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int solve(int v, int parent)
    {
        if (dp[v].first == 1)
        {
            return dp[v].second;
        }
        int ret = 1;
        for (auto &r : adj[v])
        {
            if (r == parent)
            {
                continue;
            }
            ret = max(ret, 1 + solve(r, v));
        }
        dp[v] = make_pair(1, ret);
        int smx = INT_MIN, mx = INT_MIN;

        for (auto &r : adj[v])
        {
            if (r == parent)
            {
                continue;
            }
            if (dp[r].second > mx)
            {
                smx = mx;
                mx = dp[r].second;
            }
            else if (dp[r].second > smx)
            {
                smx = dp[r].second;
            }
        }

        if (smx == INT_MIN && mx == INT_MIN)
        {
            ans[v] = 1;
        }
        else if (smx == INT_MIN)
        {
            ans[v] = 1 + mx;
        }
        else
        {
            ans[v] = 1 + mx + smx;
        }
        return dp[v].second;
    }

    int ans1()
    {
        solve(0, -1);
        return *max_element(ans.begin(), ans.end()) - 1;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        Tree t(n);

        int x, y;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            x--;
            y--;
            t.add(x, y);
        }
        cout << t.ans1();
    }
    return 0;
}