#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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
    vector<int> num(n + 2);
    vector<int> ind(n + 2);
    num[0] = 0;
    num[n + 1] = n + 1;
    ind[0] = 0;
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        ind[num[i]] = i;
    }
    int inv = 1;
    for (int i = 0; i <= n; i++)
    {
        if (ind[i] > ind[i + 1])
        {
            inv++;
        }
    }
    // cout << inv << "\n";
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        int count = 0;
        set<pair<int, int>> s;
        s.insert(mp(num[x], num[x] + 1));
        s.insert(mp(num[x] - 1, num[x]));
        s.insert(mp(num[y] - 1, num[y]));
        s.insert(mp(num[y], num[y] + 1));

        for (auto &r : s)
        {
            count -= (int)(ind[r.fi] > ind[r.se]);
        }
        s.clear();
        swap(num[x], num[y]);
        ind[num[x]] = x;
        ind[num[y]] = y;

        s.insert(mp(num[x], num[x] + 1));
        s.insert(mp(num[x] - 1, num[x]));
        s.insert(mp(num[y] - 1, num[y]));
        s.insert(mp(num[y], num[y] + 1));

        for (auto &r : s)
        {
            count += (int)(ind[r.fi] > ind[r.se]);
        }
        inv += count;
        cout << inv << "\n";
    }
    return 0;
}