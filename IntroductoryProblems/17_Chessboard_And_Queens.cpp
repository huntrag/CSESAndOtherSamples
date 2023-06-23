#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

vector<bool> r(8, false), c(8, false), d1(15, false), d2(15, false);
vector<string> a(8);

int cnt = 0;

void queen(int y)
{
    // cout << y;
    if (y == 8)
    {
        cnt++;
    }
    for (int x = 0; x < 8; x++)
    {
        if (r[y] || c[x] || d1[x + y] || d2[7 + x - y] || a[y][x] == '*')
        {
            continue;
        }
        r[y] = c[x] = d1[x + y] = d2[7 + x - y] = true;
        queen(y + 1);
        r[y] = c[x] = d1[x + y] = d2[7 + x - y] = false;
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

    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    queen(0);
    cout << cnt;
    return 0;
}