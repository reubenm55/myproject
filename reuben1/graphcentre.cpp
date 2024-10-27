// Binary tree insertion and deletion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Define a node of the tree
struct Node
{
    int data;//Data of the node(value stored in the node)
    Node* left;//Pointer to the left child node
    Node* right;//Pointer to the right child node

    //Constructor to initialize a node with a value
    Node(int value)
    {
        data = value;//set the data value of the node
        left = right = nullptr;// initialize left and right children as null(no children)
    }
};

//Function to insert a node into the tree
Node* insert(Node* root, int data)
{
    //if the tree is empty, create a new node and return it
    if(root==nullptr)
    {
        return new Node(data);//The new node becomes the root
    }
    //If the data is smaller than the root, insert it into the left subtree
    if (data<root->data)
    {
        root->left = insert(root -> left, data);
    }
    // If the data is greater than the root, insert it into the right subtree
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}
//Function to find the minimum node in a subtree
Node* findMin(Node* root)
{
    // The minimum value in a BST is always located in the leftmost node
    while (root->left != nullptr)
    {
        root = root->left;//Traverse to the leftmost node
    }
    // Return the root of the modified tree
    return root;
}
//Function to delete a node from the tree
Node* deleteNode(Node* root, int data)
{
    // If the tree is empty, return the root (which is nullptr)
    if (root == nullptr)
    {
        return root;
    }

    // If the data to delete is smaller than the root, search in the left subtree
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    // If the data to delete is larger than the root, search in the right subtre
    else if(data>root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // If the data matches the root, this is the node to be deleted
    else
    {
    //Node with only one child or no child
        if (root->left == nullptr)// if left child is null, replace with right child
        {
            Node* temp = root->right;//store the right child
            delete root;//delete the current node
            return temp;//return the child to replace the delete node
        }
        else if(root->right==nullptr)//if right child is null, replace with the left child
        {
            Node* temp = root->left;//store the left child
            delete root;//delete the current node
            return temp;//return the left child to replace the deleted node
        }
        //Node with two children:get the inorder successor
        Node* temp = findMin(root->right);

        //copy the inorder succesor's data to this node
        root->data = temp->data;

        //Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//Inorder traversal:(left,root,right):prints values in ascending order
void inorder(Node*root)
{
    if (root == nullptr)return;//base case:if node is null,return
    inorder(root->left);//recusively traverse the left subtree
    if (root == nullptr)return;
    cout << root->data << "";//print the root's data
    inorder(root->right);//recursively traverse the right subtree
}

//Preorder traversal: root,left,right
void preorder(Node*root)
{
    if (root == nullptr)return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data << "";
}

//Postorder traversal: root,left,right
void postorder(Node* root)
{
    if (root == nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "";
}
int main()
{
    Node* root = nullptr;
    int choice, value;

    while(true)
    {
        cout << "\n1.Insert\n2.Delete\n3.Inorder Traversal\n4.Preorder Travesal\n5.Postorder Traversal\n6.Exit\n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter a value to insert:";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Enter a value to delete:";
            cin >> value;
            root = deleteNode(root, value);
            break;

        case 3:
            cout << "Inorder Traversal:";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Preorder Traversal:";
            preorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal:";
            postorder(root);
            cout << endl;
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}