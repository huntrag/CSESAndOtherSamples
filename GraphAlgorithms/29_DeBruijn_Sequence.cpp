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
    vector<vector<pair<int, int>>> adj;

    Graph(int n)
    {
        this->n = n;
        adj.resize(n);
    }

    void add(int x, int y, int z)
    {
        adj[x].push_back(make_pair(y, z));
    }

    void debruijn()
    {
        stack<pair<int, int>> stk;
        vector<int> path;
        int f = log2(n);

        stk.push(adj[0].back());
        adj[0].pop_back();
        while (!stk.empty())
        {
            int cur = stk.top().first;
            if (adj[cur].size() == 0)
            {
                path.push_back(stk.top().second);
                stk.pop();
            }
            else
            {
                stk.push(adj[cur].back());
                adj[cur].pop_back();
            }
        }
        while (f--)
        {
            path.push_back(0);
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ":  ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << "( " << adj[i][j].first << ", " << adj[i][j].second << ")"
                     << " ";
            }
            cout << "\n";
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
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "10";
            return 0;
        }
        int v = pow(2, n - 1);
        Graph *g = new Graph(v);
        int mask = v / 2 - 1;
        for (int i = 0; i < v; i++)
        {
            int x = (i & mask);
            g->add(i, 2 * x + 1, 1);
            g->add(i, 2 * x, 0);
        }
        // g->print();
        g->debruijn();
    }
    return 0;
}