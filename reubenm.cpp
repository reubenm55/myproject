1.	Balanced tree maximum path sum
#include <iostream>
#include <algorithm>
#include <climits>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;  // Initialize max_sum to the smallest integer
        maxPathFromNode(root);
        return max_sum;
    }
private:
    int max_sum;  // This will store the maximum path sum
    int maxPathFromNode(TreeNode* node) {
        if (!node) {
            return 0;  // Base case: if the node is null, return 0
        }
        int left_max = std::max(maxPathFromNode(node->left), 0); // Only consider positive sums
        int right_max = std::max(maxPathFromNode(node->right), 0); // Only consider positive sums
        int current_sum = node->val + left_max + right_max;
        max_sum = std::max(max_sum, current_sum);
        return node->val + std::max(left_max, right_max);
    }

2.	Binary tree pre order traversal
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node) {
            result.push_back(node->val);   // Visit the root
            traverse(node->left, result);   // Traverse left subtree
            traverse(node->right, result);  // Traverse right subtree
        }
    }
};



Binary tree post order traversal
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node) {
            traverse(node->left, result);   // Traverse left subtree
            traverse(node->right, result);  // Traverse right subtree
            result.push_back(node->val);     // Visit the root
        }
    }
};



3.	Binary tree maximum path sum
#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;  // Initialize max_sum to the smallest integer
        maxPathFromNode(root);
        return max_sum;
    }

private:
    int max_sum;  // This will store the maximum path sum

    int maxPathFromNode(TreeNode* node) {
        if (!node) {
            return 0;  // Base case: if the node is null, return 0
        }

        // Recursively get the maximum path sum from left and right subtrees
        int left_max = std::max(maxPathFromNode(node->left), 0); // Only consider positive sums
        int right_max = std::max(maxPathFromNode(node->right), 0); // Only consider positive sums

        // Calculate the maximum path sum passing through the current node
        int current_sum = node->val + left_max + right_max;

        // Update the global maximum path sum
        max_sum = std::max(max_sum, current_sum);

        // Return the maximum path sum extending from this node
        return node->val + std::max(left_max, right_max);
    }
};


4.	Binary tree in order traversal
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node) {
            traverse(node->left, result);   // Traverse left subtree
            result.push_back(node->val);     // Visit the root
            traverse(node->right, result);  // Traverse right subtree
        }
    }
};



5.	Pre order
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

private:
    void traverse(TreeNode* node, std::vector<int>& result) {
        if (node) {
            traverse(node->left, result);   // Traverse left subtree
            traverse(node->right, result);  // Traverse right subtree
            result.push_back(node->val);     // Visit the root
        }
    }
};

