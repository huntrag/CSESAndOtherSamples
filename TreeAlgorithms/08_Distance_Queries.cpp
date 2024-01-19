#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define fi first
#define se second
const int MOD = 1e9 + 7;
const int MAX = 2e5;

class Tree
{
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> anc;

    Tree(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        anc.resize(20, vector<int>(n + 1));
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void prepare()
    {
        anc[1][1] = -1;
        prep(1, 0);
        for (int i = 1; i <= n; i++)
        {
            anc[0][i] = i;
        }

        for (int i = 2; i < anc.size(); i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (anc[i - 1][j] == 0)
                {
                    anc[i][j] = 0;
                }
                anc[i][j] = anc[i - 1][anc[i - 1][j]];
            }
        }
    }

    void prep(int i, int par)
    {
        for (auto &r : adj[i])
        {
            if (r == par)
            {
                continue;
            }
            anc[1][r] = i;
            prep(r, i);
        }
    }

    int lca(int x, int y)
    {
        if (x == y)
        {
            return x;
        }
        int i;
        for (i = 1; i < 20; i++)
        {
            if (anc[i][x] != anc[i][y])
            {
                continue;
            }
            else
            {
                break;
            }
            // cout << anc[i][x] << " " << anc[i][y] << "\n";
        }
        if (i == 1)
        {
            return anc[i][x];
        }
        return lca(anc[i - 1][x], anc[i - 1][y]);
        // return 0;
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
        int n, q;
        cin >> n >> q;
        Tree *t = new Tree(n);
        for (int i = 1; i <= n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            t->add(x, y);
        }

        t->prepare();
        cout << t->lca(4, 3);
        while (q--)
        {
            int x, y;
            cin >> x >> y;
        }
    }
    return 0;
}