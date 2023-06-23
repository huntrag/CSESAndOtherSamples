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

void kmp(string s1, string s2, vector<pair<int, int>> &ans, int fr)
{
    vector<int> lps = createlps(s2);
    // for (int i = 0; i < lps.size(); i++)
    // {
    //     cout << s2[i] << " " << lps[i] << "\n";
    // }
    int i = 0, j = 0;
    int n = s1.length(), m = s2.length();
    int count = 0;
    while (i < n)
    {
        if (j == m)
        {
            // cout << "Found at position " << i - m << "\n";
            ans.push_back(make_pair(i - m, fr));
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
        // cout << "Found at position " << i - m << "\n";
        ans.push_back(make_pair(i - m, fr));
        count++;
        j = lps[j];
    }
}

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<pair<int, int>> a;
    vector<int> ret;
    int n = words.size();
    int k = words[0].length();
    for (int i = 0; i < words.size(); i++)
    {
        kmp(s, words[i], a, i);
    }
    sort(a.begin(), a.end());

    int m = a.size();

    for (int i = 0; i < m; i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }

    int sublen = words.size() * words[0].length();

    set<int> st;
    set<int> ind;
    int j = 0;

    for (int i = 0; i < s.length() - sublen; i++)
    {
        int end = i + sublen;
        while (a[j].first < sublen)
        {
        }
    }

    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin >> ws, s);
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin >> ws, words[i]);
    }

    vector<int> ret = findSubstring(s, words);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    return 0;
}