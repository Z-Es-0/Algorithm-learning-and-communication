#include <iostream>
using namespace std;

// 定义AVL树的节点结构
struct AVLNode {
    int val;          // 节点存储的值
    int count;        // 此值在树中的出现次数
    int height;       // 此节点的树高度
    int leftSize;     // 此节点左子树的总节点数（包括重复）
    int rightSize;    // 此节点右子树的总节点数（包括重复）
    AVLNode* left;    // 指向左子节点的指针
    AVLNode* right;   // 指向右子节点的指针

    // 节点构造函数
    AVLNode(int x) : val(x), count(1), height(1), leftSize(0), rightSize(0), left(nullptr), right(nullptr) {}
};

// AVL树类定义
class AVLTree {
private:
    AVLNode* root; // 树的根节点

    // 获取节点的高度
    int height(AVLNode* N) {
        if (N == nullptr) return 0;
        return N->height;
    }

    // 获取节点的总大小（左大小 + 右大小 + 当前节点计数）
    int size(AVLNode* N) {
        if (N == nullptr) return 0;
        return N->leftSize + N->rightSize + N->count;
    }

    // 计算节点的平衡因子
    int getBalance(AVLNode* N) {
        if (N == nullptr) return 0;
        return height(N->left) - height(N->right);
    }

    // 右旋转操作
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // 执行旋转
        x->right = y;
        y->left = T2;

        // 更新高度
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // 更新大小
        y->leftSize = size(y->left);
        y->rightSize = size(y->right);
        x->leftSize = size(x->left);
        x->rightSize = size(x->right);

        // 返回新的根节点
        return x;
    }

    // 左旋转操作
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // 执行旋转
        y->left = x;
        x->right = T2;

        // 更新高度
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // 更新大小
        x->leftSize = size(x->left);
        x->rightSize = size(x->right);
        y->leftSize = size(y->left);
        y->rightSize = size(y->right);

        // 返回新的根节点
        return y;
    }

    // 插入新键到AVL树中
    AVLNode* insert(AVLNode* node, int key) {
        if (node == nullptr) return new AVLNode(key);

        if (key < node->val) {
            node->left = insert(node->left, key);
            node->leftSize++;
        } else if (key > node->val) {
            node->right = insert(node->right, key);
            node->rightSize++;
        } else {
            node->count++;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // 左左情况
        if (balance > 1 && key < node->left->val)
            return rightRotate(node);

        // 右右情况
        if (balance < -1 && key > node->right->val)
            return leftRotate(node);

        // 左右情况
        if (balance > 1 && key > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右左情况
        if (balance < -1 && key < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 计算大于给定键的节点数
    int countGreater(AVLNode* node, int key) {
        if (node == nullptr) return 0;

        if (key < node->val) {
            return node->rightSize + node->count + countGreater(node->left, key);
        } else {
            return countGreater(node->right, key);
        }
    }

    // 计算小于给定键的节点数
    int countLess(AVLNode* node, int key) {
        if (node == nullptr) return 0;

        if (key > node->val) {
            return node->leftSize + node->count + countLess(node->right, key);
        } else {
            return countLess(node->left, key);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // 对外提供的插入方法
    void insert(int key) {
        root = insert(root, key);
    }

    // 对外提供的计算大于给定值的节点数方法
    int countGreater(int key) {
        return countGreater(root, key);
    }

    // 对外提供的计算小于给定值的节点数方法
    int countLess(int key) {
        return countLess(root, key);
    }
};

int main() {
    AVLTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    cout << "Count of nodes greater than 3 is: " << tree.countGreater(3) << endl;

    tree.insert(3);
    cout << "Count of nodes greater than 2 after inserting another 3 is: " << tree.countGreater(2) << endl;

    return 0;
}
