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
#define c2i(c) ((int)c - (int)'a')

string removeDuplicateLetters(string s)
{
    vector<int> freq(26, 0);
    vector<bool> vis(26, false);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        freq[c2i(s[i])]++;
    }

    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        freq[c2i(s[i])]--;
        if (vis[c2i(s[i])])
        {
            continue;
        }

        while (!stk.empty() && s[stk.top()] > s[i] && freq[c2i(s[stk.top()])] > 0)
        {
            vis[c2i(s[stk.top()])] = false;
            stk.pop();
        }

        vis[c2i(s[i])] = true;
        stk.push(i);
    }

    string res;
    while (!stk.empty())
    {
        res.push_back(s[stk.top()]);
        stk.pop();
    }
    reverse(res.begin(), res.end());

    return res;
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
    // cin>>test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        cout << removeDuplicateLetters(s);
    }
    return 0;
}