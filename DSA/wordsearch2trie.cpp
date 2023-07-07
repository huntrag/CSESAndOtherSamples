#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<ll>> vvll;
#define MOD 1000000007
#define fi first
#define se second

#define c2i(c) ((int)c - (int)'a')
class Trie
{
public:
    Trie *child[26];
    int isEnd;

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = -1;
    }

    void insert(string &word, int ind, int flag)
    {
        int index = c2i(word[ind]);
        // cout<<word<<"\n";
        if (child[index] == NULL)
        {
            child[index] = new Trie();
        }
        if (word.length() - 1 == ind)
        {
            child[index]->isEnd = flag;
            return;
        }
        child[index]->insert(word, ind + 1, flag);
    }

    void search(int i, int j, vvc &a, set<int> &ans, vvi &vis, vvi &moves)
    {
        if (vis[i][j])
        {
            return;
        }
        int ind = c2i(a[i][j]);
        if (child[ind] == NULL)
        {
            return;
        }
        if (child[ind]->isEnd != -1)
        {
            ans.insert(child[ind]->isEnd);
            // return; iske wajah se error
        }
        vis[i][j] = true;
        int ni, nj;
        for (auto &move : moves)
        {
            ni = i + move[0];
            nj = j + move[1];

            if (ni < 0 || ni >= a.size() || nj < 0 || nj >= a[0].size() || vis[ni][nj])
            {
                continue;
            }

            child[ind]->search(ni, nj, a, ans, vis, moves);
        }
        vis[i][j] = false;
    }
};

vector<string> findWords(vector<vector<char>> &a, vector<string> &words)
{
    Trie *t = new Trie();
    int i = 0;
    for (auto &word : words)
    {
        t->insert(word, 0, i);
        i++;
    }
    set<int> ans;
    vvi moves{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vvi vis(a.size(), vi(a[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            t->search(i, j, a, ans, vis, moves);
        }
    }
    vector<string> ans1;

    for (auto &r : ans)
    {
        ans1.push_back(words[r]);
    }

    return ans1;
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
    }
    return 0;
}