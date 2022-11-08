#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 10000007
#define fi first
#define se second
typedef pair<int, int> pii;

vector<pii> moves{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

void bfs1(vector<vector<int>> &dis, vector<vector<bool>> vis, queue<pii> q)
{
    int n = vis.size(), m = vis[0].size();
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        for (auto &mv : moves)
        {
            int x = cur.fi + mv.fi, y = cur.se + mv.se;
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || vis[x][y])
            {
                continue;
            }
            else
            {
                vis[x][y] = true;
                q.push(make_pair(x, y));
                dis[x][y] = min(dis[x][y], dis[cur.fi][cur.se] + 1);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pii> mons;
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, MOD));
    pii st;
    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                vis[i][j] = true;
            }
            else if (s[j] == 'A')
            {
                st.fi = i;
                st.se = j;
            }
            else if (s[j] == 'M')
            {
                q.push({i, j});
                dis[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
    if ((st.fi == 0 || st.se == 0 || st.fi == n - 1 || st.se == m - 1))
    {
        cout << "YES\n"
             << 0;
        return 0;
    }
    bfs1(dis, vis, q);
    vector<vector<int>> play(n, vector<int>(m, MOD));
    vector<int> parent(n * m);
    bool success = false;
    parent[st.fi * m + st.se] = -1;
    while (!q.empty())
    {
        q.pop();
    }
    q.push(st);
    int x, y;
    play[st.fi][st.se] = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (dis[i][j] == MOD)
    //         {
    //             cout << 'X';
    //         }
    //         else
    //         {
    //             cout << dis[i][j];
    //         }
    //         cout << " ";
    //     }
    //     cout << "\n";
    // }
    while (!q.empty() && !success)
    {
        pii cur = q.front();
        q.pop();
        for (auto &mv : moves)
        {
            x = cur.fi + mv.fi, y = cur.se + mv.se;
            if (vis[x][y] || x <= 0 || x >= n - 1 || y <= 0 || y >= m - 1)
            {
                if (!vis[x][y] && (x == 0 || y == 0 || x == n - 1 || y == m - 1))
                {
                    play[x][y] = play[cur.fi][cur.se] + 1;
                    parent[x * m + y] = cur.fi * m + cur.se;
                    if (play[x][y] < dis[x][y])
                    {
                        success = true;
                        break;
                    }
                }
                continue;
            }
            else
            {
                vis[x][y] = true;
                play[x][y] = play[cur.fi][cur.se] + 1;
                parent[x * m + y] = cur.fi * m + cur.se;
                if (play[x][y] < dis[x][y])
                {
                    q.push(make_pair(x, y));
                }
            }
        }
    }
    // cout << "--------" << x << " " << y << "---------------------\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (play[i][j] == MOD)
    //         {
    //             cout << 'X';
    //         }
    //         else
    //         {
    //             cout << play[i][j];
    //         }
    //         cout << " ";
    //     }
    //     cout << "\n";
    // }

    if (!success)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        stack<char> s;
        int cur = x * m + y, prev;
        int sh = st.fi * m + st.se;
        while (cur != sh)
        {
            prev = parent[cur];
            int dif = cur - prev;
            if (dif == 1)
            {
                s.push('R');
            }
            else if (dif == -1)
            {
                s.push('L');
            }
            else if (dif == m)
            {
                s.push('D');
            }
            else
            {
                s.push('U');
            }
            cur = prev;
        }
        cout << s.size() << "\n";
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }
    return 0;
}