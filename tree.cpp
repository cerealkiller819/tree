#include <iostream>
#include <string>
#include <initializer_list>

struct TreeNode {
    std::string key; 
    TreeNode* left;  
    TreeNode* right; 

    TreeNode(std::string k)
        : key(k)
        , left(nullptr)
        , right(nullptr)
        {}
};

class BinaryTree {
public:
    TreeNode* root; 
    BinaryTree() : root(nullptr) {}

    BinaryTree(std::initializer_list<std::string> terms) : root(nullptr) {
        for (const auto& term : terms) {
            insert(term);
        }
    }

    void PreOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->key << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }

    void InOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        InOrder(node->left);
        std::cout << node->key << " ";
        InOrder(node->right);
    }

    void PostOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        PostOrder(node->left);
        PostOrder(node->right);
        std::cout << node->key << " ";
    }

    std::string Min() {
        TreeNode* current = root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->key;
    }

    std::string Max() {
        TreeNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->key;
    }

    void insert(const std::string& key) {
        if (root == nullptr) {
            root = new TreeNode(key);
        } else {
            insertHelper(root, key);
        }
    }

private:
    void insertHelper(TreeNode* node, const std::string& key) {
        if (key < node->key) {
            if (node->left == nullptr) {
                node->left = new TreeNode(key);
            } 
            else {
                insertHelper(node->left, key);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(key);
            } 
            else {
                insertHelper(node->right, key);
            }
        }
    }
};

int main() {
    BinaryTree tree{"3", "1", "4", "2", "5"};

    tree.PreOrder(tree.root);
    std::cout << std::endl;

    tree.InOrder(tree.root);
    std::cout << std::endl;

    tree.PostOrder(tree.root);
    std::cout << std::endl;

    std::cout<<tree.Min() << std::endl;

    
    std::cout<<tree.Max() << std::endl;

    return 0;
}
