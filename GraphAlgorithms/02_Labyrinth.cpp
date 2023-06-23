#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef pair<int, int> pii;
#define MOD 1000000007
#define fi first
#define se second

vector<pii> moves{{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

bool bfs(pii st, pii en, vector<vector<bool>> &vis, vector<int> &p)
{
    int n = vis.size(), m = vis[0].size();
    queue<pii> q;
    q.push(st);
    vis[st.fi][st.se] = true;
    bool mil = false;
    while (!q.empty() && !mil)
    {
        pii cur = q.front();
        q.pop();
        for (auto mv : moves)
        {
            int x = cur.fi + mv.fi, y = cur.se + mv.se;
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1 || vis[x][y])
            {
                continue;
            }
            pii hehe = make_pair(x, y);
            q.push(hehe);
            vis[x][y] = true;
            p[x * m + y] = cur.fi * m + cur.se;
            if (hehe == en)
            {
                mil = true;
                break;
            }
        }
    }
    return mil;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    pair<int, int> st, en;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
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
            else if (s[j] == 'B')
            {
                en.fi = i;
                en.se = j;
            }
        }
    }
    vector<int> p(n * m);
    bool mil = bfs(st, en, vis, p);
    if (mil)
    {
        cout << "YES\n";
        stack<char> s;
        int sr = st.first * m + st.se;
        int cur = en.fi * m + en.se;
        int prev;
        while (cur != sr)
        {
            prev = p[cur];
            int x = cur - prev;
            if (x == m)
            {
                s.push('D');
            }
            else if (x == -m)
            {
                s.push('U');
            }
            else if (x == 1)
            {
                s.push('R');
            }
            else
            {
                s.push('L');
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
    else
    {
        cout << "NO";
    }
    return 0;
}