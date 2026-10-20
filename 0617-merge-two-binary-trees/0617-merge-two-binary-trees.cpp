class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL) return root2;
        if (root2 == NULL) return root1;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root1, root2});
        while (!st.empty()) {
            auto [node1, node2] = st.top();
            st.pop();
            node1->val += node2->val;
            if (node1->right && node2->right) {
                st.push({node1->right, node2->right});
            } else if (node1->right == NULL) {
                node1->right = node2->right;
            }
            if (node1->left && node2->left) {
                st.push({node1->left, node2->left});
            } else if (node1->left == NULL) {
                node1->left = node2->left;
            }
        }
        return root1;
    }
};