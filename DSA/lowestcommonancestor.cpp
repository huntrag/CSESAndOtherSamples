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

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }

    TreeNode *lft = lowestCommonAncestor(root->left, p, q);
    TreeNode *rght = lowestCommonAncestor(root->right, p, q);

    if (lft != NULL && rght != NULL)
    {
        return root;
    }
    else if (lft == NULL)
    {
        return rght;
    }
    else
    {
        return lft;
    }
    return NULL;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if ((root->val > p->val) && (root->val > q->val))
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if ((root->val < p->val) && (root->val < q->val))
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
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