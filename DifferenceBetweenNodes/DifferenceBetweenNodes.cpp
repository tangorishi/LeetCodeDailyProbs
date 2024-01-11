#include <climits>
#include <algorithm>

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, root->val, root->val);
    }

private:
    int findMaxDiff(TreeNode* node, int minValue, int maxValue) {
        if (!node)
            return maxValue - minValue;

        
        minValue = std::min(minValue, node->val);
        maxValue = std::max(maxValue, node->val);

        
        int leftDiff = findMaxDiff(node->left, minValue, maxValue);
        int rightDiff = findMaxDiff(node->right, minValue, maxValue);

        
        return std::max({leftDiff, rightDiff, maxValue - minValue});
    }
};
