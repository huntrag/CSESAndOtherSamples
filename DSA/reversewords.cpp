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

string reverseWords(string s)
{
    auto it = s.begin();
    auto prev = s.begin();
    while (it != s.end())
    {
        if (*it == ' ')
        {
            reverse(prev, it);
            it++;
            prev = it;
        }
        else
        {
            it++;
        }
    }
    reverse(prev, it);
    reverse(s.begin(), s.end());

    int j = 0;
    int i = 0;
    int n = s.length();
    bool flag = false;
    // initialzation
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    while (i < n)
    {
        while (i < n)
        {
            s[j] = s[i];
            j++;
            i++;
            if (s[i] == ' ')
            {
                s[j] = s[i];
                i++;
                j++;
                break;
            }
        }
        while (i < n && s[i] == ' ')
        {
            i++;
        }
    }
    s.erase(s.begin() + j, s.end());
    while (s.length() > 0 && s.back() == ' ')
    {
        s.pop_back();
    }
    return s;
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
        cout << reverseWords(s);
    }
    return 0;
}