#include "tree.h"

#include <limits>
#include <queue>

namespace tree_algo {

namespace {

void preorderImpl(TreeNode* root, std::vector<int>& order) {
    // 前序遍历顺序：根 -> 左 -> 右。
    if (root == nullptr) {
        return;
    }

    order.push_back(root->val);
    preorderImpl(root->left, order);
    preorderImpl(root->right, order);
}

void inorderImpl(TreeNode* root, std::vector<int>& order) {
    // 中序遍历顺序：左 -> 根 -> 右。
    if (root == nullptr) {
        return;
    }

    inorderImpl(root->left, order);
    order.push_back(root->val);
    inorderImpl(root->right, order);
}

void postorderImpl(TreeNode* root, std::vector<int>& order) {
    // 后序遍历顺序：左 -> 右 -> 根。
    if (root == nullptr) {
        return;
    }

    postorderImpl(root->left, order);
    postorderImpl(root->right, order);
    order.push_back(root->val);
}

bool isValidBSTImpl(TreeNode* root, long long lower, long long upper) {
    // 空节点天然满足二叉搜索树性质。
    if (root == nullptr) {
        return true;
    }

    // 当前节点必须严格落在允许区间内。
    if (root->val <= lower || root->val >= upper) {
        return false;
    }

    // 左子树上界为当前节点值，右子树下界为当前节点值。
    return isValidBSTImpl(root->left, lower, root->val) &&
           isValidBSTImpl(root->right, root->val, upper);
}

}  // namespace

TreeNode::TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

// 前序遍历：先访问根节点，再依次处理左子树和右子树。
std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> order;
    preorderImpl(root, order);
    return order;
}

// 中序遍历：在二叉搜索树中，中序结果天然是升序序列。
std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> order;
    inorderImpl(root, order);
    return order;
}

// 后序遍历：适合处理“先算子树，再处理当前节点”的问题。
std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> order;
    postorderImpl(root, order);
    return order;
}

// 层序遍历：按从上到下、从左到右的顺序访问二叉树。
std::vector<int> levelOrderTraversal(TreeNode* root) {
    std::vector<int> order;
    if (root == nullptr) {
        return order;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    // 队列中的节点代表当前尚未处理的层序访问顺序。
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        order.push_back(node->val);

        if (node->left != nullptr) {
            q.push(node->left);
        }

        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return order;
}

// 最大深度：根节点到最远叶子节点路径上的节点数。
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    // 当前节点的深度等于左右子树最大深度加一。
    const int leftDepth = maxDepth(root->left);
    const int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 判断是否为合法二叉搜索树。
bool isValidBST(TreeNode* root) {
    return isValidBSTImpl(root,
                          std::numeric_limits<long long>::lowest(),
                          std::numeric_limits<long long>::max());
}

// 在二叉搜索树中查找目标值。
TreeNode* searchBST(TreeNode* root, int target) {
    TreeNode* current = root;

    // 利用 BST 左小右大的性质逐步缩小搜索范围。
    while (current != nullptr) {
        if (current->val == target) {
            return current;
        }

        if (target < current->val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return nullptr;
}

}  // namespace tree_algo
