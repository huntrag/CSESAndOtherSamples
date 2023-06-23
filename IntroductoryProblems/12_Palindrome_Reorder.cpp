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

    int crate[26]{0};
    for (int i = 0; i < (int)s.length(); i++)
    {
        int a = 'A';
        crate[(int)s[i] - a]++;
    }
    bool axe = false;
    for (int i = 0; i < 26; i++)
    {
        if (crate[i] % 2 == 1)
        {
            if ((int)s.length() % 2 == 0 || axe)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            if (!axe && (int)s.length() % 2 == 1)
            {
                axe = true;
            }
        }
    }
    int n = (int)s.length();
    char a[n];
    int start = 0;
    int end = n - 1;
    int mid = (int)end / 2;

    for (int i = 0; i < 26; i++)
    {
        char c = (char)'A' + i;
        if (crate[i] % 2 == 1)
        {
            a[mid] = c;
            crate[i]--;
        }

        for (int j = 0; j < crate[i] / 2; j++)
        {
            a[start++] = c;
        }
        for (int j = 0; j < crate[i] / 2; j++)
        {
            a[end--] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }

    return 0;
}