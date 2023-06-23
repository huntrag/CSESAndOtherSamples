// Prob link - https://www.spoj.com/problems/AKBAR/
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
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        int n, r, m;
        cin >> n >> r >> m;
        vector<list<int>> adj(n + 1);
        int x, y;
        for (int i = 0; i < r; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<pair<int, int>> power(m);
        for (int i = 0; i < m; i++)
        {
            cin >> power[i].fi >> power[i].se;
        }
        bool err = false;
        vector<int> guard(n + 1, -1);
        vector<int> lavda(n + 1, -1);

        for (int sold_no = 0; !err && sold_no < m; sold_no++)
        {
            int city = power[sold_no].fi;
            int dis = power[sold_no].se;

            if (guard[city] != -1 && guard[city] != sold_no)
            {
                err = true;
                break;
            }

            queue<int> q;
            q.push(city);
            lavda[city] = dis;
            guard[city] = sold_no;

            while (!err && !q.empty())
            {
                int cur_city = q.front();
                q.pop();

                if (lavda[cur_city] == 0)
                {
                    if (guard[cur_city] == sold_no)
                    {
                        continue;
                    }
                    else
                    {
                        err = true;
                        break;
                    }
                }

                for (auto &neigh : adj[cur_city])
                {
                    if (guard[neigh] == -1)
                    {
                        guard[neigh] = guard[cur_city];
                        lavda[neigh] = lavda[cur_city] - 1;
                        q.push(neigh);
                    }
                    else
                    {
                        if (guard[neigh] == guard[cur_city])
                        {
                            continue;
                        }
                        else
                        {
                            err = true;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (guard[i] == -1)
            {
                err = true;
            }
        }

        if (err)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}

// Soluton accepted --YEESSSS!!