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

vi createlps(string s)
{
    int i = 0, j = 1, n = s.length();
    vi a(n);
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

int len(vector<string> &dict, int i)
{
    return dict[i].length();
}

int kmp(string s1, string s2, vvi &ind, int index, vector<string> &dict)
{
    vi lps = createlps(s2);
    int i = 0, j = 0;
    int n = s1.length(), m = s2.length();
    int count = 0;
    while (i < n)
    {
        if (j == m)
        {
            // cout << "Found at position " << i - m << "\n";
            ind[i - m].push_back(i - m + len(dict, index));
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
        ind[i - m].push_back(i - m + len(dict, index));
        count++;
        j = lps[j];
    }

    return count;
}

bool solve(int i, vvi &ind, vector<bool> &dp, vector<string> &dict)
{
    if (i == dp.size())
    {
        return true;
    }
    if (dp[i] == true)
    {
        return true;
    }
    bool ans = false;
    for (int j = 0; j < ind[i].size(); j++)
    {
        ans = ans | solve(i + len(dict, ind[i][j]), ind, dp, dict);
    }
    dp[i] = ans;
    return ans;
}

bool wordBreak(string s, vector<string> &dict)
{
    int n = dict.size();
    vvi ind(s.length());

    for (int i = 0; i < n; i++)
    {
        kmp(s, dict[i], ind, i, dict);
    }

    // for (int i = 0; i < ind.size(); i++)
    // {
    //     cout << i << " - ";
    //     for (int j = 0; j < ind[i].size(); j++)
    //     {
    //         cout << ind[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vi vis(s.length(), false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    bool flag = false;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &neigh : ind[node])
        {
            if (neigh == s.length())
            {
                flag = true;
                break;
            }
            if (!vis[neigh])
            {
                q.push(neigh);
                vis[neigh] = true;
            }
        }
        if (flag)
        {
            break;
        }
    }

    return flag;
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
    // cin>>test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        int n;
        cin >> n;
        vector<string> dict(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin >> ws, dict[i]);
        }
        cout << wordBreak(s, dict);
    }
    return 0;
}