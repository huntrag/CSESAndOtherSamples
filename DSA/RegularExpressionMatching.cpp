#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

bool isMatch(string s, string r);

map<pair<int, int>, bool> m;

bool isMatch(string s, string r)
{
    if (m.find(make_pair(s.length(), r.length())) != m.end())
    {
        return m[make_pair(s.length(), r.length())];
    }
    bool res = false;
    bool next = false;
    if (s.length() == 0 && r.length() == 0)
    {
        res = true;
        cout << s << " " << r << " " << (res) << "\n";
        m[make_pair(s.length(), r.length())] = res;
        return res;
    }

    if (s.length() == 0 && r.length() >= 2 && r[1] == '*')
    {
        res = true;
        next = isMatch(s, r.substr(2));
        m[make_pair(s.length(), r.length())] = (res && next);
        return (res && next);
    }

    if (s.length() == 0 || r.length() == 0)
    {
        res = false;
        cout << s << " " << r << " " << (res) << "\n";
        m[make_pair(s.length(), r.length())] = (res);
        return res;
    }

    if (s[0] == r[0])
    {
        res = true;
        if (r.length() >= 2 && r[1] == '*')
        {
            next = (isMatch(s, r.substr(2)) || isMatch(s.substr(1), r.substr(2)) || isMatch(s.substr(1), r));
        }
        else
        {
            next = isMatch(s.substr(1), r.substr(1));
        }
    }
    else
    {
        if (r[0] == '.')
        {
            res = true;
            if (r.length() >= 2 && r[1] == '*')
            {
                next = (isMatch(s, r.substr(2)) || isMatch(s.substr(1), r.substr(2)) || isMatch(s.substr(1), r));
            }
            else
            {
                next = isMatch(s.substr(1), r.substr(1));
            }
        }
        else if (r.length() >= 2 && r[1] == '*')
        {
            res = true;
            next = isMatch(s, r.substr(2));
        }
        else
        {
            res = false;
            next = false;
        }
    }
    cout << s << " " << r << " " << (res && next) << "\n";
    m[make_pair(s.length(), r.length())] = (res && next);
    return (res && next);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        string s, r;
        getline(cin >> ws, s);
        getline(cin >> ws, r);

        cout << isMatch(s, r);
    }
    return 0;
}