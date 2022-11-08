#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second
vector<vector<int>> edge;
vector<bool> ansFlag;
vector<bool> vis;
stack<int> ans;
bool dfs(int node)
{
    vis[node] = true;
    ans.push(node);
    ansFlag[node] = true;

    for (auto r : edge[node])
    {
        if (!vis[r])
        {
            if (dfs(r))
            {
                return true;
            }
        }
        if (ansFlag[r])
        {
            ans.push(r);
            return true;
        }
    }

    ans.pop();
    ansFlag[node] = false;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    edge.resize(n + 1);
    ansFlag.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i))
            {
                break;
            }
        }
    }
    if (ans.empty())
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> hehe;
        int temp = ans.top();
        while (!ans.empty())
        {
            hehe.push_back(ans.top());
            if (hehe.back() == temp and hehe.size() != 1)
            {
                break;
            }
            ans.pop();
        }
        reverse(hehe.begin(), hehe.end());
        cout << hehe.size() << "\n";
        for (auto u : hehe)
        {
            cout << u << " ";
        }
    }
    return 0;
}