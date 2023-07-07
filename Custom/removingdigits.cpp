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

string removeKdigits(string num, int k)
{
    int n = num.size();
    k = n - k;
    stack<char> stk;
    if (k == 0)
    {
        return "0";
    }
    for (int i = 0; i < n; i++)
    {
        int rem = n - i;
        if (k - stk.size() == rem)
        {
            stk.push(num[i]);
        }
        else
        {
            if (stk.empty())
            {
                stk.push(num[i]);
                continue;
            }

            while (!stk.empty() && stk.top() > num[i])
            {
                if (k - stk.size() == rem)
                {
                    break;
                }
                // cout << i << " " << stk.size() << " " << n - i << "\n";
                stk.pop();
            }

            if (stk.size() < k)
            {
                stk.push(num[i]);
            }
        }
        cout << i << " " << stk.size() << "\n";
    }

    string res;
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }
    res.push_back('0');

    while (res.length() > 1 && res.back() == '0')
    {
        res.pop_back();
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
        int k;
        cin >> k;

        cout << removeKdigits(s, k);
    }
    return 0;
}