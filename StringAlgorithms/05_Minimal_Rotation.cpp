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

#define char2ind(c) ((int)c - (int)'a')

bool comp(vi &a, vi &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < b[i])
        {
            return false;
        }
        else if (a[i] > b[i])
        {
            return true;
        }
        else
        {
            continue;
        }
    }
    return true;
}

string mini(string s)
{
    string r = s + s;
    int n = s.length();
    vvi a(n, vi(27, 0));

    for (int i = 0; i < n; i++)
    {
        a[i][char2ind(s[i])]++;
    }

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         a[i][j] = a[i - 1][j];
    //     }
    //     a[i][char2ind(s[i - 1])]--;
    //     a[i][char2ind(r[n + i - 1])]++;
    // }

    sort(a.begin(), a.end(), comp);

    for (int i = 0; i < n; i++)
    {
        cout << a[i][26] << " ";
    }

    return r.substr(a[0][26], n);
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
        cout << mini(s);
    }
    return 0;
}