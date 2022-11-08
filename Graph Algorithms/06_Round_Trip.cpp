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
    while (m--)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    vector<int> vis(n + 1, 0);
    vector<int> parent(n + 1);
    int cur;
    bool mil = false;
    for (int i = 1; i <= n && !mil; i++)
    {
        stack<int> q;
        q.push(i);

        while (!q.empty() && !mil)
        {
            cur = q.top();
            q.pop();
            for (auto &r : edge[cur])
            {
                if (vis[r])
                {
                    if (parent[cur] == r || parent[r] == cur)
                    {
                        continue;
                    }
                    else
                    {
                        int temp = parent[r];
                        parent[temp] = r;
                        parent[r] = cur;

                        mil = true;
                        break;
                    }
                }
                else
                {
                    vis[r] = true;
                    q.push(r);
                    parent[r] = cur;
                }
            }
        }
    }
    if (!mil)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> s;
    s.push_back(cur);
    int st = parent[cur];
    while (st != cur)
    {
        s.push_back(st);
        st = parent[st];
    }
    s.push_back(cur);
    cout << s.size() << "\n";
    for (auto &r : s)
    {
        cout << r << " ";
    }
    return 0;
}