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
    string s;
    getline(cin >> ws, s);
    map<string, bool> m;
    vector<string> res;
    sort(s.begin(), s.end());
    do
    {
        if (!m[s])
        {
            m[s] = true;
            res.push_back(s);
        }
    } while (next_permutation(s.begin(), s.end()));
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
