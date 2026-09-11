1class Solution {
2public: 
3    unordered_set<int> seen;
4
5    bool findTarget(TreeNode* root, int k) {
6        if (!root) return false;
7
8        // 1. Check if the complement exists in our set
9        if (seen.count(k - root->val)) return true;
10
11        // 2. Insert current node's value into the set
12        seen.insert(root->val);
13
14        // 3. Recurse for left and right subtrees
15        return findTarget(root->left, k) || findTarget(root->right, k);
16    }
17};