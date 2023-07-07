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
    vi parent;
    vi sz;
    multiset<int, greater<int>> mst;

    Graph(int n)
    {
        this->n = n;
        sz.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
            mst.insert(1);
        }
    }

    int root(int x)
    {
        if (x != parent[x])
        {
            return root(parent[x]);
        }
        return x;
    }

    void join(int x, int y)
    {
        int x1 = root(x);
        int y1 = root(y);
        if (x1 != y1)
        {
            if (sz[x1] < sz[y1])
            {
                join(y1, x1);
                return;
            }
            parent[y1] = x1;
            rem(sz[x1]);
            rem(sz[y1]);
            sz[x1] = sz[x1] + sz[y1];

            mst.insert(sz[x1]);
        }
    }

    void rem(int x)
    {
        auto it = mst.find(x);
        if (it == mst.end())
        {
            return;
        }
        mst.erase(it);
    }

    void get()
    {
        cout << mst.size() << " " << *mst.begin() << "\n";
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
            g->join(x, y);
            g->get();
        }
    }
    return 0;
}