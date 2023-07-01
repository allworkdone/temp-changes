#include <limits.h>

class BST
{
    BinaryTreeNode<int> *root;

    bool searchHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return searchHelper(data, node->left);
        }
        else
        {
            return searchHelper(data, node->right);
        }
    }

    BinaryTreeNode<int> *insertHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *n = new BinaryTreeNode<int>(data);
            return n;
        }
        if (node->data >= data)
        {
            node->left = insertHelper(data, node->left);
        }
        else
        {
            node->right = insertHelper(data, node->right);
        }
        return node;
    }

    BinaryTreeNode<int> *removeHelper(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data < node->data)
        {
            node->left = removeHelper(data, node->left);
        }
        else if (data > node->data)
        {
            node->right = removeHelper(data, node->right);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minnode = node->right;
                while (minnode->left != NULL)
                {
                    minnode = minnode->left;
                }
                int replacement = minnode->data;
                node->data = replacement;
                node->right = removeHelper(replacement, node->right);
                return node;
            }
        }
        return node;
    }

    void printHelper(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        std::cout << node->data << ":";
        if (node->left)
        {
            std::cout << "L:" << node->left->data << ",";
        }
        if (node->right)
        {
            std::cout << "R:" << node->right->data;
        }
        std::cout << std::endl;
        if (node->left)
            printHelper(node->left);
        if (node->right)
            printHelper(node->right);
    }

    void deleteTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        deleteTree(root);
    }

    void remove(int data)
    {
        root = removeHelper(data, root);
    }

    void print()
    {
        printHelper(root);
    }

    void insert(int data)
    {
        root = insertHelper(data, root);
    }

    bool search(int data)
    {
        return searchHelper(data, root);
    }
};