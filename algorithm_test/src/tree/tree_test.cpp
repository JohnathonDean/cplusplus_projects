#include "tree.h"

#include <iostream>
#include <string>
#include <vector>

namespace {

void printResult(const std::string& name, bool passed) {
    std::cout << name << ": " << (passed ? "PASS" : "FAIL") << std::endl;
}

bool isEqual(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    return lhs == rhs;
}

}  // namespace

int main() {
    // 构造一棵标准二叉搜索树：
    //         5
    //       /   \
    //      3     7
    //     / \   / \
    //    2   4 6   8
    tree_algo::TreeNode node5(5);
    tree_algo::TreeNode node3(3);
    tree_algo::TreeNode node7(7);
    tree_algo::TreeNode node2(2);
    tree_algo::TreeNode node4(4);
    tree_algo::TreeNode node6(6);
    tree_algo::TreeNode node8(8);

    node5.left = &node3;
    node5.right = &node7;
    node3.left = &node2;
    node3.right = &node4;
    node7.left = &node6;
    node7.right = &node8;

    printResult(
        "preorderTraversal",
        isEqual(tree_algo::preorderTraversal(&node5), {5, 3, 2, 4, 7, 6, 8})
    );

    printResult(
        "inorderTraversal",
        isEqual(tree_algo::inorderTraversal(&node5), {2, 3, 4, 5, 6, 7, 8})
    );

    printResult(
        "postorderTraversal",
        isEqual(tree_algo::postorderTraversal(&node5), {2, 4, 3, 6, 8, 7, 5})
    );

    printResult(
        "levelOrderTraversal",
        isEqual(tree_algo::levelOrderTraversal(&node5), {5, 3, 7, 2, 4, 6, 8})
    );

    printResult("maxDepth", tree_algo::maxDepth(&node5) == 3);
    printResult("isValidBST_true", tree_algo::isValidBST(&node5));
    printResult("searchBST_hit",
                tree_algo::searchBST(&node5, 6) != nullptr &&
                tree_algo::searchBST(&node5, 6)->val == 6);
    printResult("searchBST_miss", tree_algo::searchBST(&node5, 10) == nullptr);

    // 构造一棵非法 BST：节点 6 出现在根节点 5 的左子树中。
    tree_algo::TreeNode badRoot(5);
    tree_algo::TreeNode badLeft(3);
    tree_algo::TreeNode badRight(7);
    tree_algo::TreeNode badWrong(6);

    badRoot.left = &badLeft;
    badRoot.right = &badRight;
    badLeft.right = &badWrong;

    printResult("isValidBST_false", !tree_algo::isValidBST(&badRoot));

    return 0;
}
