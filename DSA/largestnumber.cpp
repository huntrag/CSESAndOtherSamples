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

bool comp(string &a, string &b)
{
    string first = a + b;
    string second = b + a;

    if (first.compare(second) > 0)
    {
        return true;
    }
    return false;
}

string largestNumber(vector<int> &a)
{
    int n = a.size();
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
        str[i] = to_string(a[i]);
    }

    sort(str.begin(), str.end(), comp);
    string s = "";

    for (int i = 0; i < n; i++)
    {
        s.append(str[i]);
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
        vi a;
        int x;
        while (cin >> x)
        {
            a.push_back(x);
        }
        cout << largestNumber(a);
    }
    return 0;
}