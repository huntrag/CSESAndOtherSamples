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

vi zalgo(string a)
{
    vi z(a.length());
    int n = z.size();
    int l = 0, r = 0, k;
    z[0] = -1;
    for (int i = 0; i < n; i++)
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
        string s;
        getline(cin >> ws, s);
        vi z = zalgo(s);
        int n = s.length();
        for (int i = 1; i < z.size(); i++)
        {
            if (z[i] + i == n)
            {
                cout << i << " ";
            }
        }
        cout << n;
    }
    return 0;
}