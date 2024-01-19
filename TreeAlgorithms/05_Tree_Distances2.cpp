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
    vll count;
    vll ret;

    Tree(int n)
    {
        this->n = n;
        adj.resize(n + 1);
        count.resize(n + 1);
        ret.resize(n + 1);
    }

    void add(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll num(ll i, ll par)
    {
        ll tot = 1;
        for (auto &r : adj[i])
        {
            if (r == par)
            {
                continue;
            }
            tot += num(r, i);
        }
        count[i] = tot;
        return tot;
    }

    void said()
    {
        num(1, -1);
        for (int i = 1; i <= n; i++)
        {
            ret[1] += count[i];
        }
        as(1, ret[1], -1);

        for (int i = 1; i <= n; i++)
        {
            cout << ret[i] << " ";
        }
    }

    void as(ll i, ll dad, ll par)
    {
        ll remain = n - count[i];
        ret[i] = dad + remain - count[i];
        for (auto &r : adj[i])
        {
            if (r == par)
            {
                continue;
            }
            as(r, ret[i], i);
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
        Tree *t = new Tree(n);
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            t->add(x, y);
        }
        t->said();
    }
    return 0;
}