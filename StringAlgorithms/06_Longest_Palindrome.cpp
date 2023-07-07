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

string longestPalindrome(string s)
{
    int n = s.length();
    // cout << n << "\n";
    // int count = 0;
    int len = 2 * n + 1;
    vi lps(len, 0);
    int lo = -1, ro = -1, le = -1, re = -1;
    int ind, ind1, ind2;
    for (int i = 0; i < lps.size(); i++)
    {
        if ((i & 1))
        {
            // it is odd baby
            if (i <= ro)
            {
                // take minimum of outer palindrome edge or the prev stored mirror value
                lps[i] = min(lps[lo + (ro - i)], (ro - i) / 2);
            }
            ind = i / 2;
            while (ind - lps[i] >= 0 && ind + lps[i] < n)
            {
                if (s[ind - lps[i]] == s[ind + lps[i]])
                {
                    lps[i]++;
                }
                else
                {
                    break;
                }
            }
            lps[i]--;
            if (i + lps[i] * 2 >= ro)
            {
                ro = i + lps[i] * 2;
                lo = i - lps[i] * 2;
            }
        }
        else
        {
            if (i <= re)
            {
                lps[i] = min(lps[le + (re - i)], (re - i) / 2);
            }
            ind2 = i / 2;
            ind1 = ind2 - 1;
            while (ind1 - lps[i] >= 0 && ind2 + lps[i] < n)
            {
                if (s[ind1 - lps[i]] == s[ind2 + lps[i]])
                {
                    lps[i]++;
                }
                else
                {
                    break;
                }
            }
            // lps[i]--;
            if (i + lps[i] * 2 >= re)
            {
                re = i + lps[i] * 2;
                le = i - lps[i] * 2;
            }
        }
        // cout << i << " " << lps[i] << "\n";
    }
    for (int i = 0; i < lps.size(); i++)
    {
        lps[i] = 2 * lps[i] + (i & 1);
    }
    // cout << "\n";
    ind = max_element(lps.begin(), lps.end()) - lps.begin();
    int st = ind / 2 - lps[ind] / 2;

    return s.substr(st, lps[ind]);
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

        cout << longestPalindrome(s);
    }
    return 0;
}