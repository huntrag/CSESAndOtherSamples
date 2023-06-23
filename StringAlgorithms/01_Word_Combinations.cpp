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

#define char2ind(c) ((int)c - (int)'a')

ll ans = 0;

class Trie
{
public:
    Trie *child[26];
    bool isEnd;

    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }

    void insert(string word)
    {
        int index = char2ind(word[0]);
        // cout<<word<<"\n";
        if (child[index] == NULL)
        {
            child[index] = new Trie();
            if (word.length() == 1)
            {
                child[index]->isEnd = true;
                return;
            }
            child[index]->insert(word.substr(1));
        }
        else
        {
            if (word.length() == 1)
            {
                child[index]->isEnd = true;
                return;
            }
            child[index]->insert(word.substr(1));
        }
    }

    void solve(Trie *root, string &s, int st, int cnt, vll &dp)
    {
        if (st + cnt - 1 >= s.length())
        {
            return;
        }
        int i = char2ind(s[st + cnt - 1]);
        if (child[i] == NULL)
        {
            return;
        }
        else
        {
            if (child[i]->isEnd)
            {
                dp[st] = (dp[st] + dp[st + cnt]) % MOD;
            }

            child[i]->solve(root, s, st, cnt + 1, dp);
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--)
    {
        string s;
        getline(cin >> ws, s);
        int k;
        cin >> k;

        Trie *t = new Trie();

        for (int i = 0; i < k; i++)
        {
            string temp;
            getline(cin >> ws, temp);

            t->insert(temp);
        }
        int n = s.length();

        vll dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            t->solve(t, s, i, 1, dp);
        }
        // for (int i = 0; i <= n; i++)
        // {
        //     cout << dp[i] << " ";
        // }
        // cout << "\n";
        cout << dp[0];
    }
    return 0;
}