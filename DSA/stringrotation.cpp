#include <bits/stdc++.h>

using namespace std;

string diffarr(string s)
{
    vector<int> v(s.length() - 1);
    string ans;
    for (int i = 1; i < s.length(); i++)
    {
        v[i - 1] = ((s[i] - s[i - 1]) + 26) % 26;
        ans.push_back(v[i - 1] + '0');
    }

    return ans;
}

int main()
{

    int n;
    cin >> n;
    vector<string> a(n);

    for (auto &str : a)
    {
        getline(cin >> ws, str);
    }
    map<string, vector<string>> mp;
    for (auto &str : a)
    {
        string r = diffarr(str);
        cout << r << "\n";
        mp[r].push_back(str);
    }

    vector<vector<string>> v;

    for (auto &i : mp)
    {
        v.push_back(i.second);
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}