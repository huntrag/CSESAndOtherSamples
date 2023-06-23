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

    void solve(Trie *root, string &s, int x, int ind, vi path, vvi &ans)
    {
        if (s.length() == 0)
        {
            return;
        }
        int index = char_to_ind(s[ind]);
        if (child[index] == NULL)
        {
            return;
        }
        if (ind == s.length() - 1)
        {
            if (child[index]->isEnd)
            {
                path.push_back(x + 1);
                ans.push_back(path);
            }
            return;
        }

        if (child[index]->isEnd)
        {
            path.push_back(x + 1);
            root->solve(root, s, 0, ind + 1, path, ans);
            path.pop_back();
            child[index]->solve(root, s, x + 1, ind + 1, path, ans);
        }
        else
        {
            child[index]->solve(root, s, x + 1, ind + 1, path, ans);
        }
    }
};

vector<string> wordBreak(string s, vector<string> &dict)
{
    Trie *t = new Trie;

    for (auto &word : dict)
    {
        t->insert(word);
    }
    vvi ans;
    vi path;
    t->solve(t, s, 0, 0, path, ans);

    vector<string> ret;

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < ans.size(); i++)
    {
        string temp;
        int cnt = 0;
        for (int j = 0; j < ans[i].size(); j++)
        {
            for (int k = 0; k < ans[i][j]; k++)
            {
                temp.push_back(s[cnt]);
                cnt++;
            }
            temp.push_back(' ');
        }
        temp.pop_back();
        ret.push_back(temp);
    }

    return ret;
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
        vector<string> ret = wordBreak(s, dict);
        for (int i = 0; i < ret.size(); i++)
        {
            cout << ret[i] << "\n";
        }
    }
    return 0;
}