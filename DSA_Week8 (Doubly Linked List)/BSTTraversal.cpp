//Create a binary search tree and traverse it in preorder, inorder and postorder traversal methods
//Aakanxa Modha
//230970031

#include <iostream>
using namespace std;

class TreeNode 
{
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) 
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree 
{
  private:
    TreeNode* root;

  public:
    BinarySearchTree() 
    {
        root = nullptr;
    }

    TreeNode* insertNode(TreeNode* node, int value) 
    {
        if (node == nullptr) 
        {
            node = new TreeNode(value);
        } 
        else 
          if (value <= node->data) 
          {
            node->left = insertNode(node->left, value);
          } 
          else 
          {
            node->right = insertNode(node->right, value);
          }
          return node;
    }

    void insert(int value) 
    {
        root = insertNode(root, value);
        cout << value << " inserted into the binary search tree.\n";
    }

    void preorderTraversal(TreeNode* node) 
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(TreeNode* node) 
    {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode* node) 
    {
        if (node == nullptr)
            return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void traverse() 
    {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;

        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;

        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() 
{
    BinarySearchTree bst;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> value;
        bst.insert(value);
    }

    cout << "Tree traversals:\n";
    bst.traverse();
    return 0;
}
