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

#define char_to_ind(c) ((int)c - (int)'a')
class Trie
{
public:
    Trie *child[26];
    bool isEnd;

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }

    void insert(string word)
    {
        int index = char_to_ind(word[0]);
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

    bool search(string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = char_to_ind(word[0]);

        if (child[index] == NULL)
        {
            return false;
        }
        else if (word.length() == 1)
        {
            return child[index]->isEnd;
        }
        else
        {
            return child[index]->search(word.substr(1));
        }
    }

    bool startsWith(string prefix)
    {
        if (prefix.length() == 0)
        {
            return true;
        }
        int index = char_to_ind(prefix[0]);

        if (child[index] == NULL)
        {
            return false;
        }
        else
        {
            return child[index]->startsWith(prefix.substr(1));
        }
    }

    void solve(string s, vector<bool> &dp, int sind)
    {
        if (s.length() == 0)
        {
            return;
        }
        int index = char_to_ind(s[0]);
        if (child[index] == NULL)
        {
            return;
        }
        else
        {
            dp[sind] = dp[sind] | child[index]->isEnd;
            child[index]->solve(s.substr(1), dp, sind + 1);
        }
    }
};

bool wordBreak(string s, vector<string> &dict)
{
    Trie *t = new Trie();
    for (int i = 0; i < dict.size(); i++)
    {
        t->insert(dict[i]);
    }
    vector<bool> dp(s.length());

    t->solve(s, dp, 0);
    for (int i = 1; i < s.length(); i++)
    {
        if (dp[i - 1])
        {
            t->solve(s.substr(i), dp, i);
        }
    }
    return dp[s.length() - 1];
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
        int n;
        cin >> n;
        vector<string> dict(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin >> ws, dict[i]);
        }
        cout << wordBreak(s, dict);
    }
    return 0;
}