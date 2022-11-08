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
    int n, m, x;
    cin >> n >> m;
    multiset<int> s;
    vector<int> cus(m);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> cus[i];
    }

    for (int i = 0; i < m; i++)
    {
        if (s.empty())
        {
            cout << "-1\n";
            continue;
        }
        auto search = s.lower_bound(cus[i]);
        if (*search == cus[i])
        {
            cout << cus[i] << "\n";
            s.erase(s.find(cus[i]));
        }
        else if (search == s.end())
        {
            search--;
            cout << *search << "\n";
            s.erase(s.find(*search));
        }
        else if (*search > cus[i])
        {
            if (search == s.begin())
            {
                cout << -1 << "\n";
            }
            else
            {
                search--;
                cout << *search << "\n";
                s.erase(s.find(*search));
            }
        }
    }

    return 0;
}