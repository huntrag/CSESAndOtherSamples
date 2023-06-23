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

vector<string> solve(string s, int dots)
{
    vector<string> ans;
    if (dots == 3)
    {
        if (s[0] == '0' && s.length() > 1)
        {
            return ans;
        }
        else if (s.length() <= 0 || s.length() > 3)
        {
            return ans;
        }
        else
        {
            int data = stoi(s);
            if (data <= 255)
            {
                ans.push_back(s);
            }
            return ans;
        }
    }

    if (s.length() == 0)
    {
        return ans;
    }
    int j = 0;
    if (s.length() >= j + 1)
    {
        vector<string> temp = solve(s.substr(1), dots + 1);
        for (int i = 0; i < temp.size(); i++)
        {
            string u;
            for (int o = 0; o <= j; o++)
            {
                u.push_back(s[o]);
            }
            u.push_back('.');
            u.append(temp[i]);
            ans.push_back(u);
        }
    }
    j++;

    if (s.length() >= j + 1 && s[0] - '0' >= 1)
    {
        vector<string> temp = solve(s.substr(2), dots + 1);

        for (int i = 0; i < temp.size(); i++)
        {
            string u;
            for (int o = 0; o <= j; o++)
            {
                u.push_back(s[o]);
            }
            u.push_back('.');
            u.append(temp[i]);
            ans.push_back(u);
        }
    }

    j++;
    int t = stoi(s.substr(0, 3));
    if (s.length() >= j + 1 && t >= 100 && t <= 255)
    {
        vector<string> temp = solve(s.substr(3), dots + 1);

        for (int i = 0; i < temp.size(); i++)
        {
            string u;
            for (int o = 0; o <= j; o++)
            {
                u.push_back(s[o]);
            }
            u.push_back('.');
            u.append(temp[i]);
            ans.push_back(u);
        }
    }

    return ans;
}
vector<string> restoreIpAddresses(string s)
{
    return solve(s, 0);
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
        vector<string> v = restoreIpAddresses(s);

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << "\n";
        }
    }
    return 0;
}