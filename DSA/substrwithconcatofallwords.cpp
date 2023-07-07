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

    void insert(string s, int pos)
    {
        insertutil(s, 0, pos);
    }

    void insertutil(string s, int ind, int pos)
    {
        if (ind >= s.length())
        {
            return;
        }
        int i = c2i(s[ind]);

        if (child[i] == NULL)
        {
            child[i] = new Trie();
        }
        if (ind == s.length() - 1)
        {
            child[i]->isEnd = pos;
            return;
        }
        child[i]->insertutil(s, ind + 1, pos);
    }

    int search(string s, int ind, int end)
    {
        if (ind >= end)
        {
            return -1;
        }

        int i = c2i(s[ind]);

        if (child[i] == NULL)
        {
            return -1;
        }
        if (ind == end - 1)
        {
            return child[i]->isEnd;
        }
        return child[i]->search(s, ind + 1, end);
    }
};

vector<int>
findSubstring(string s, vector<string> &words)
{
    int n = s.length();
    multiset<string> mst;
    for (auto &word : words)
    {
        mst.insert(word);
    }
    int word = words[0].length();
    int window = word * words.size();

    vi counts;
    int i = 0;
    Trie *t = new Trie();
    for (auto &r : mst)
    {
        counts.push_back(mst.count(r));
        t->insert(r, i);
        i++;
    }
    int m = i;
    vi ans;
    for (i = 0; i < n - window + 1; i++)
    {
        vi vis(m);
        int j = 0;
        for (; j < words.size(); j++)
        {
            int get = t->search(s, i + j * word, i + j * word + word);
            if (get != -1)
            {
                vis[get]++;
                if (vis[get] > counts[get])
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (j == words.size())
        {
            ans.push_back(i);
        }
    }

    return ans;
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

        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            getline(cin >> ws, a[i]);
        }

        vi ans = findSubstring(s, a);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}