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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

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
        Trie *t = new Trie();
        t->insert("raghav");
        cout << t->search("raghv");
    }
    return 0;
}