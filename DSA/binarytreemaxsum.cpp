
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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

class Solution
{
public:
    int mx = INT_MIN;
    int counter = 0;

    pair<TreeNode *, int> setdfs(TreeNode *root)
    {
        pair<TreeNode *, int> ret;
        if (root == NULL)
        {
            ret.first = NULL;
            ret.second = 0;
            return ret;
        }
        TreeNode *cur = new TreeNode();
        pair<TreeNode *, int> lft, rght;
        lft = setdfs(root->left);
        rght = setdfs(root->right);

        cur->left = lft.first;
        cur->right = rght.first;

        cur->val = root->val + max(0, lft.second) + max(0, rght.second);

        ret.first = cur;
        ret.second = max(max(0, root->val), max(root->val + lft.second, root->val + rght.second));
        return ret;
    }

    int getdfs(TreeNode *root)
    {
        if (root == NULL)
        {
            cout << "null ";
            return INT_MIN;
        }
        int lft = getdfs(root->left);
        int rght = getdfs(root->right);

        // cout<<root->val<<" ";
        return max(max(lft, rght), root->val);
    }

    int maxPathSum(TreeNode *root)
    {
        TreeNode *cur = root;
        pair<TreeNode *, int> dp1 = setdfs(cur);
        TreeNode *dp = dp1.first;
        queue<TreeNode *> q;
        q.push(dp);
        int mx = INT_MIN;
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == NULL)
            {
                // cout<<"null,";
                continue;
            }
            mx = max(mx, cur->val);
            // cout<<cur->val<<",";
            q.push(cur->left);
            q.push(cur->right);
        }

        return mx;
    }
};