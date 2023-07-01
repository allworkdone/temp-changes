#include <climits>
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    bool search(int data, BinaryTreeNode<int> *node)
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
            return search(data, node->left);
        }
        else
        {
            return search(data, node->right);
        }
    }
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if (data < node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = remove(data, node->right);
        }
        else if (data < node->data)
        {
            node->left = remove(data, node->left);
        }
        else
        {
            if (node->left == NULL and node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *ans = node->right;
                node->right = NULL;
                delete node;
                return ans;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *ans = node->left;
                node->left = NULL;
                delete node;
                return ans;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(rightMin, node->right);
                return node;
            }
        }
    }
    void print(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L:" << node->left->data << ",";
        }

        if (node->right != NULL)
        {
            cout << "R:" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
    }

public:
    void remove(int data)
    {
        root = remove(data, root);
    }

    void print()
    {
        print(root);
    }

    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

    bool search(int data)
    {
        return search(data, root);
    }
};