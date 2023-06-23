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

string sortinp(string &s)
{
    int tot[26]{0};
    int n = s.length();
    string r(n, '\0');
    for (int i = 0; i < n; i++)
    {
        tot[s[i] - 'a']++;
    }

    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        while (tot[i] > 0)
        {
            r[j] = (char)'a' + i;
            tot[i]--;
            j++;
        }
    }
    return r;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    vector<pair<string, int>> pr(n);
    for (int i = 0; i < n; i++)
    {
        pr[i] = make_pair(sortinp(strs[i]), i);
    }
    sort(pr.begin(), pr.end());
    vector<vector<string>> res(n);
    int cnt = 0;
    res[0].push_back(strs[pr[0].second]);
    string prev = pr[0].first;
    for (int i = 1; i < n; i++)
    {
        if (prev.compare(pr[i].first) == 0)
        {
            res[cnt].push_back(strs[pr[i].second]);
        }
        else
        {
            cnt++;
            res[cnt].push_back(strs[pr[i].second]);
            prev = pr[i].first;
        }
    }
    vector<vector<string>> fin(cnt + 1);

    for (int i = 0; i <= cnt; i++)
    {
        fin[i].resize(res[i].size());
        for (int j = 0; j < res[i].size(); j++)
        {
            fin[i][j] = res[i][j];
        }
    }

    return fin;
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

        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            string r;
            getline(cin >> ws, r);
            s[i] = r;
        }
        vector<vector<string>> res = groupAnagrams(s);

        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[i].size(); j++)
            {
                cout << res[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}