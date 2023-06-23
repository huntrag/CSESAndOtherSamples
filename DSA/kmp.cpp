#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
#define MOD 1000000007
#define fi first
#define se second

vector<int> createlps(string s)
{
    int i = 0, j = 1, n = s.length();
    vector<int> a(n);
    a[0] = 0;

    while (j < n)
    {
        if (s[i] != s[j])
        {
            if (i == 0)
            {
                i = 0;
                a[j] = 0;
                j++;
            }
            else
            {
                i = a[i - 1];
            }
        }
        else
        {
            i++;
            a[j] = i;
            j++;
        }
    }

    return a;
}

int kmp(string s1, string s2)
{
    vector<int> lps = createlps(s2);
    for (int i = 0; i < lps.size(); i++)
    {
        cout << s2[i] << " " << lps[i] << "\n";
    }
    int i = 0, j = 0;
    int n = s1.length(), m = s2.length();
    int count = 0;
    while (i < n)
    {
        if (j == m)
        {
            cout << "Found at position " << i - m << "\n";
            count++;
            j = lps[j - 1];
        }
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
                continue;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
    if (j == m)
    {
        cout << "Found at position " << i - m << "\n";
        count++;
        j = lps[j];
    }

    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1;
    string s2;

    getline(cin >> ws, s1);
    getline(cin >> ws, s2);

    cout << kmp(s1, s2);
    return 0;
}