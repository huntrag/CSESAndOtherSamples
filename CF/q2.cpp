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

bool check(vector<vector<int>> &a, int x)
{
    // row
    for (int i = 0; i < 3; i++)
    {
        bool flag = true;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != x)
            {
                flag = false;
            }
        }
        if (flag)
        {
            return true;
        }
    }

    // col
    for (int j = 0; j < 3; j++)
    {
        bool flag = true;
        for (int i = 0; i < 3; i++)
        {
            if (a[i][j] != x)
            {
                flag = false;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    bool flag = true;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][i] != x)
        {
            flag = false;
        }
    }
    if (flag)
    {
        return true;
    }
    flag = true;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][2 - i] != x)
        {
            flag = false;
        }
    }
    if (flag)
    {
        return true;
    }
    return false;
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
    cin >> test;
    while (test--)
    {
        vvi a(3, vi(3));

        for (int i = 0; i < 3; i++)
        {
            string s;
            getline(cin >> ws, s);
            for (int j = 0; j < 3; j++)
            {
                if (s[j] == 'O')
                {
                    a[i][j] = 1;
                }
                else if (s[j] == 'X')
                {
                    a[i][j] = 2;
                }
                else if (s[j] == '+')
                {
                    a[i][j] = 3;
                }
            }
        }

        map<int, char> m;
        m[1] = 'O';
        m[2] = 'X';
        m[3] = '+';
        bool flag = false;
        for (int i = 1; i <= 3; i++)
        {
            if (check(a, i))
            {
                cout << m[i] << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "DRAW\n";
        }
    }
    return 0;
}