// Hash funciton banaya bande ne

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

vector<string> findRepeatedDnaSequences(string s)
{

    unordered_map<size_t, int> MP;
    hash<string> hash_fn;
    vector<string> ret;

    for (int i = 0; i < int(s.size()) - 9; ++i)
        if (MP[hash_fn(s.substr(i, 10))]++ == 1)
            ret.push_back(s.substr(i, 10));

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
    }
    return 0;
}