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

class Graph
{
public:
    int n;
    vvi adj;
    vi ind;
    vi oud;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        ind.resize(n + 1);
        oud.resize(n + 1);
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        oud[x]++;
        ind[y]++;
    }

    void tele()
    {
        int st = 1;
        int icnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (oud[i] > ind[i])
            {
                if (oud[i] == ind[i] + 1)
                {
                    icnt++;
                    st = i;
                }
                else
                {
                    cout << "IMPOSSIBLE";
                    return;
                }
            }
        }
        if (icnt > 1)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        stack<int> stk;
        vector<int> path;
        stk.push(st);

        while (!stk.empty())
        {
            int cur = stk.top();
            if (adj[cur].size() == 0)
            {
                path.push_back(cur);
                stk.pop();
            }
            else
            {
                int nxt = adj[cur].back();
                oud[cur]--;
                ind[nxt]--;
                adj[cur].pop_back();
                stk.push(nxt);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (oud[i] != 0 || ind[i] != 0)
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }

        reverse(path.begin(), path.end());
        if (path.back() != n)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
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

        g->tele();
    }
    return 0;
}