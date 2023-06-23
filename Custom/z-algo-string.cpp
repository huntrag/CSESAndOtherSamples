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

vi zalgo(string m, string p)
{
    string a("");
    vi z(p.length() + 1 + m.length());
    a.append(p);
    a.push_back('$');
    a.append(m);

    int n = z.size();
    int l = 0, r = 0, k;
    z[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && a[r - l] == a[r])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else
        {
            k = i - l;

            if (z[k] < r - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && a[r - l] == a[r])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }

    return z;
}

vi search(string &m, string &p)
{
    vi z = zalgo(m, p);
    vi ans;
    for (int i = p.size() + 1; i < z.size(); i++)
    {
        if (z[i] == p.size())
        {
            ans.push_back(i - p.size() - 1);
        }
    }
    return ans;
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
        string m, pat;
        getline(cin >> ws, m);
        getline(cin >> ws, pat);
        vi ans = search(m, pat);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}