#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define pb push_back
#define MOD 1000000007
#define fi first
#define se second

class Graph
{
public:
    int n;
    vector<unordered_set<int>> adj;
    vi deg;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        deg.resize(n + 1);
    }

    void add(int x, int y)
    {
        adj[x].insert(y);
        adj[y].insert(x);
        deg[x]++;
        deg[y]++;
    }

    void iterEuler()
    {
        stack<int> stk;
        vector<int> ans;
        stk.push(1);
        while (!stk.empty())
        {
            int cur = stk.top();
            if (deg[cur] == 0)
            {
                ans.push_back(cur);
                stk.pop();
            }
            else
            {
                int nxt = *adj[cur].begin();
                deg[cur]--;
                deg[nxt]--;
                adj[cur].erase(nxt);
                adj[nxt].erase(cur);
                stk.push(nxt);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (deg[i] > 0)
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }

        if (ans[0] != 1 || ans.back() != 1)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
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
        int n, m;
        cin >> n >> m;
        Graph *g = new Graph(n);
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            g->add(x, y);
        }
        g->iterEuler();
    }
    return 0;
}