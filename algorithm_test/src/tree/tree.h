#ifndef TREE_H
#define TREE_H

#include <vector>

namespace tree_algo {

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int value);
};

std::vector<int> preorderTraversal(TreeNode* root);
std::vector<int> inorderTraversal(TreeNode* root);
std::vector<int> postorderTraversal(TreeNode* root);
std::vector<int> levelOrderTraversal(TreeNode* root);
int maxDepth(TreeNode* root);
bool isValidBST(TreeNode* root);
TreeNode* searchBST(TreeNode* root, int target);

}  // namespace tree_algo

#endif
