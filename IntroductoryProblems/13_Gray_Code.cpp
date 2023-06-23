#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1e9 + 7
#define fi first
#define se second

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<string> s(1);
    s[0] = "";

    for (int i = 1; i <= n; i++)
    {
        vector<string> res(2 * s.size());
        for (int j = 0; j < s.size(); j++)
        {
            res[j] = "0" + s[j];
        }
        int cnt = s.size();
        for (int j = s.size() - 1; j >= 0; j--)
        {
            res[cnt++] = "1" + s[j];
        }
        s.resize(res.size());

        for (int j = 0; j < s.size(); j++)
        {
            s[j] = res[j];
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << "\n";
    }
    return 0;
}