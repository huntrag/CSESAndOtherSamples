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
#define deb(x) cout << x << endl
#define deb2(x, y) cout << x << ' ' << y << endl
#define deb3(x, y, z) cout << x << ' ' << y << ' ' << z << endl

bool isSeries(string &s)
{
    int n = s.length();
    int i = 0;
    int end = n - 1;
    if (n % 2 == 0)
    {
        if (s[i] == ')' && s[n - 1] == '(')
        {
            i = 1;
            end = n - 2;
        }
        else if (s[i] == ')')
        {
            return false;
        }
        else if (s[n - 1] == '(')
        {
            return false;
        }
    }
    else
    {
        if (s[i] == ')' && s[n - 1] == '(')
        {
            return false;
        }
        if (s[i] == ')')
        {
            i = 1;
        }
        else if (s[n - 1] == '(')
        {
            end = n - 2;
        }
        else
        {
            return false;
        }
    }
    int count = 0;
    bool flag = false;
    for (; i <= end; i++)
    {
        if (s[i] == ')')
        {
            count--;
        }
        else
        {
            count++;
        }
        if (count < 0 || count > 1)
        {
            flag = true;
        }
    }

    if (flag || count != 0)
    {
        return false;
    }
    return true;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        if (isSeries(s))
        {
            if (s.compare("()") == 0)
            {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < s.length(); i++)
            {
                cout << '(';
            }
            for (int i = 0; i < s.length(); i++)
            {
                cout << ')';
            }
            cout << "\n";
        }
        else
        {
            cout << "YES\n";
            for (int i = 0; i < s.length(); i++)
            {
                cout << "()";
            }
            cout << "\n";
        }
    }
    return 0;
}