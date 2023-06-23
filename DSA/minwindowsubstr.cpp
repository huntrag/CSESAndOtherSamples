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

string minWindow(string s, string t)
{
    string fin;
    if (t.length() > s.length())
    {
        return fin;
    }
    int swin = 0;
    int ewin = t.length() - 1;
    int sans = 0;
    int eans = 0;

    // vi tfreq(26, 0), sfreq(26, 0);
    unordered_map<char, int> tfreq, sfreq;
    int scount = 0;
    int tcount = 0;
    for (int i = 0; i < t.length(); i++)
    {
        tfreq[t[i]]++;
    }

    for (auto &r : tfreq)
    {
        if (r.second > 0)
        {
            tcount += r.second;
        }
    }
    int n = s.length();

    for (int i = 0; i < n && i <= ewin; i++)
    {
        sfreq[s[i]]++;
        if (tfreq[s[i]] > 0 && tfreq[s[i]] >= sfreq[s[i]])
        {
            scount++;
        }
    }
    int ans = INT_MAX;
    ewin++;
    while (swin < n && ewin <= n)
    {
        if (ewin == n || tcount == scount)
        {
            if (tcount == scount && (ewin - swin) < ans)
            {
                ans = ewin - swin;
                sans = swin;
                eans = ewin;
            }
            sfreq[s[swin]]--;
            if (tfreq[s[swin]] > 0 && tfreq[s[swin]] > sfreq[s[swin]])
            {
                scount--;
            }
            swin++;
        }
        else
        {
            sfreq[s[ewin]]++;
            if (tfreq[s[ewin]] > 0 && tfreq[s[ewin]] >= sfreq[s[ewin]])
            {
                scount++;
            }
            ewin++;
        }
        // cout << s.substr(swin, ewin - swin) << " " << scount << " " << tcount << "\n";
    }
    // cout << ans << "\n";
    if (ans == INT_MAX)
    {
        return fin;
    }
    fin = s.substr(sans, ans);

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
    // cin>>test;
    while (test--)
    {
        string s, t;
        getline(cin >> ws, s);
        getline(cin >> ws, t);
        cout << minWindow(s, t);
    }
    return 0;
}