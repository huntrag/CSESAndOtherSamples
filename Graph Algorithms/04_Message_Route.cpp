#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y;
    cin >> n >> m;
    vector<list<int>> edge(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    queue<int> q;
    vector<int> parent(n + 1, -1);
    q.push(1);
    parent[1] = 0;
    while (!q.empty() && parent[n] == -1)
    {
        int cur = q.front();
        q.pop();
        for (auto &r : edge[cur])
        {
            if (parent[r] == -1)
            {
                parent[r] = cur;
                q.push(r);
            }
        }
    }
    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    stack<int> s;
    int cur = parent[n];
    while (cur > 0)
    {
        s.push(cur);
        cur = parent[cur];
    }
    cout << s.size() + 1 << "\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << n;
    return 0;
}