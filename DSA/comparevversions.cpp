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
int compareVersion(string v1, string v2)
{
    vector<int> i1, i2;
    i1.push_back(-1);
    i2.push_back(-1);
    for (int i = 0; i < v1.length(); i++)
    {
        if (v1[i] == '.')
        {
            i1.push_back(i);
        }
    }

    for (int i = 0; i < v2.length(); i++)
    {
        if (v2[i] == '.')
        {
            i2.push_back(i);
        }
    }

    if (i1.size() > i2.size())
    {
        while (i2.size() < i1.size())
        {
            v2.push_back('.');
            i2.push_back(v2.size() - 1);
            v2.push_back('0');
        }
    }
    else
    {
        while (i1.size() < i2.size())
        {
            v1.push_back('.');
            i1.push_back(v1.size() - 1);
            v1.push_back('0');
        }
    }
    i1.push_back(v1.size());
    i2.push_back(v2.size());
    int n = i1.size();
    int i = 1;
    while (i < n)
    {
        // cout << i1[i] << " " << i2[i] << "\n";
        int f1 = stoi(v1.substr(i1[i - 1] + 1, i1[i] - i1[i - 1] - 1));
        int f2 = stoi(v2.substr(i2[i - 1] + 1, i2[i] - i2[i - 1] - 1));
        i++;
        if (f1 == f2)
        {
            continue;
        }
        else if (f1 < f2)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
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
        string s1, s2;
        getline(cin >> ws, s1);
        getline(cin >> ws, s2);

        cout << compareVersion(s1, s2);
    }
    return 0;
}