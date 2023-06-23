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
    vi dp;
    vi vis;

    Tree(int x)
    {
        n = x;
        adj.resize(n + 1);
        dp.resize(n + 1);
        vis.resize(n + 1);
    }

    void add(int parent, int child)
    {
        adj[parent].push_back(child);
    }

    int doit(int v)
    {
        if (vis[v])
        {
            return dp[v];
        }
        int ans = adj[v].size();
        for (auto &des : adj[v])
        {
            ans = ans + doit(des);
        }
        dp[v] = ans;
        vis[v] = true;
        return dp[v];
    }

    void util()
    {
        for (int i = 1; i <= n; i++)
        {
            doit(i);
        }
    }

    int get(int i)
    {
        return dp[i];
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
    // cin>>test;
    while (test--)
    {
        int n;
        cin >> n;
        Tree a(n);
        int x;
        for (int i = 2; i <= n; i++)
        {
            cin >> x;
            a.add(x, i);
        }
        a.util();
        for (int i = 1; i <= n; i++)
        {
            cout << a.get(i) << " ";
        }
    }
    return 0;
}