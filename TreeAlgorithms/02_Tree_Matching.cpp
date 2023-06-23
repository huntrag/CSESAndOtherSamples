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
    vector<vector<int>> adj;
    vvi dp;
    vvi vis;

    Tree(int x)
    {
        n = x;
        adj.resize(n);
        dp.resize(n, vi(2));
        vis.resize(n, vi(2));
    }

    void add(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int solve(int v, int parent, int prev_sat)
    {
        if (vis[v][prev_sat])
        {
            return dp[v][prev_sat];
        }
        int mx = 0;
        if (prev_sat == 0)
        {
            int ans = 0;
            for (auto &r : adj[v])
            {
                if (r == parent)
                {
                    continue;
                }
                else
                {
                    ans = ans + solve(r, v, 0);
                }
            }
            for (auto &r : adj[v])
            {
                if (r == parent)
                {
                    continue;
                }
                else
                {
                    mx = max(mx, ans + 1 + solve(r, v, 1) - dp[r][0]);
                }
            }
        }
        else
        {
            for (auto &r : adj[v])
            {
                if (r == parent)
                {
                    continue;
                }
                else
                {
                    mx = mx + solve(r, v, 0);
                }
            }
        }
        vis[v][prev_sat] = 1;
        dp[v][prev_sat] = mx;
        return mx;
    }

    int give_me()
    {
        return solve(0, -1, 0);
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
        int x, y;
        Tree t(n);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y;
            x--;
            y--;

            t.add(x, y);
        }
        cout << t.give_me();
    }
    return 0;
}