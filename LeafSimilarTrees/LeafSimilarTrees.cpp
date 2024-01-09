class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        inOrder(root1, leaves1);
        inOrder(root2, leaves2);

        return leaves1 == leaves2;
    }

private:
    void inOrder(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) return;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return;
        }

        inOrder(root->left, leaves);
        inOrder(root->right, leaves);
    }
};
