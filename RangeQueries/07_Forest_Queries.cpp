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
#define left(x) 2 * x + 1
#define right(x) 2 * x + 2

int n;

ll sizeofsegmenttree(ll n)
{
    ll k = (ll)ceil((double)log2(n));
    return 2 * pow(2, k) - 1;
}

void createy(vvi &t, vvi &a, int vy, int vyl, int vyr, int vx, int vxl, int vxr)
{
    if (vyl > vyr)
    {
        return;
    }
    if (vyl == vyr)
    {
        if (vxl == vxr)
        {
            t[vy][vx] = a[vyl][vxl];
        }
        else
        {
            t[vy][vx] = t[vy][left(vx)] + t[vy][right(vx)];
        }
    }
    else
    {
        int vym = (vyl + vyr) / 2;
        createy(t, a, left(vy), vyl, vym, vx, vxl, vxr);
        createy(t, a, right(vy), vym + 1, vyr, vx, vxl, vxr);
        t[vy][vx] = t[left(vy)][vx] + t[right(vy)][vx];
    }
    // cout << vxl << " " << vyl << " " << vxr << " " << vyr << "\n";
}

void createx(vvi &t, vvi &a, int vx, int vxl, int vxr)
{
    if (vxl > vxr)
    {
        return;
    }
    // cout << vxl << " " << vxr << "\n";
    if (vxl != vxr)
    {
        int vxm = (vxr + vxl) / 2;
        createx(t, a, left(vx), vxl, vxm);
        createx(t, a, right(vx), vxm + 1, vxr);
    }

    createy(t, a, 0, 0, n - 1, vx, vxl, vxr);
}

int sumy(vvi &t, int vx, int vy, int vyl, int vyr, int ty, int by)
{
    if (ty > by)
    {
        return 0;
    }
    if (ty == vyl && by == vyr)
    {
        return t[vy][vx];
    }
    int vym = (vyl + vyr) / 2;
    return sumy(t, vx, left(vy), vyl, vym, ty, min(vym, by)) +
           sumy(t, vx, right(vy), vym + 1, vyr, max(vym + 1, ty), by);
}

int sumx(vvi &t, int vx, int vxl, int vxr, int lx, int rx, int ty, int by)
{
    if (lx > rx)
    {
        return 0;
    }
    if (lx == vxl && rx == vxr)
    {
        return sumy(t, vx, 0, 0, n - 1, ty, by);
        // return -1;
    }
    int vxm = (vxl + vxr) / 2;
    return sumx(t, left(vx), vxl, vxm, lx, min(vxm, rx), ty, by) +
           sumx(t, right(vx), vxm + 1, vxr, max(lx, vxm + 1), rx, ty, by);
    // return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        int q;
        cin >> n >> q;
        vvi a(n, vi(n, 0));

        for (int i = 0; i < n; i++)
        {
            string str;
            getline(cin >> ws, str);
            for (int j = 0; j < n; j++)
            {
                if (str[j] == '*')
                {
                    a[i][j] = 1;
                }
            }
        }
        // int sz = sizeofsegmenttree(n);
        int sz = 4 * n;
        vvi t(sz, vi(sz, 0));
        createx(t, a, 0, 0, n - 1);

        while (q--)
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            y1--;
            x1--;
            y2--;
            x2--;
            cout << sumx(t, 0, 0, n - 1, x1, x2, y1, y2) << "\n";
        }
    }
    return 0;
}