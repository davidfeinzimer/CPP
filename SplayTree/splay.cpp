#include <iostream>
#include "splay.h"
using namespace std;

// Splay notes
//  zig-zig = left child of left child or right child of right child
//  zig-zag = left child of right child or right child of left child

bool findBST(node*&, int);
node* insertBST(node*, int);
node* newNode(int);

bool find(node*& root, int value) {
    bool res = findBST(root, value);
    splay(root);
    return res;
}

bool findBST(node *& root, int value) {
    if(!root) {
        return root; // Empty tree, or not found
    }
    else if(root->key == value) {
        return root;
    }
    else if(root->key < value) {
        return find(root->right, value);
    }
    else if(root->key > value) {
        return find(root->left, value);
    } else {
        return false;
    }
}

node* insert(node* root, int value) {
    insertBST(root, value);
    return splay(root);
}

node* insertBST(node* root, int key) {
    /* If the tree is empty, return a new Node */
    if (root == nullptr) {
        return newNode(key);
    }
    else if(root->key == key) {
        return root;
    }
    /* Otherwise, recur down the tree */
    else if (key < root->key) {
        node * lchild = insertBST(root->left, key);
        root->left = lchild;
        // Set parent of root of left subtree
        lchild->parent = root;
    }
    else if (key > root->key) {
        node * rchild = insertBST(root->right, key);
        root->right  = rchild;
        // Set parent of root of right subtree
        rchild->parent = root;
    }
    /* return the (unchanged) Node pointer */
    return root;
}

node* newNode(int key) {
    node * Node = new node();
    Node -> key   = key;
    Node -> left  = nullptr;
    Node -> parent = nullptr;
    Node -> right = nullptr;
    return(Node);
}

void rotate(node* child, node* parent) {
    assert(parent != nullptr && child != nullptr);
    assert(child == parent->left || child == parent->right);
    if(child == parent->left) {
        node* y = child->right;
        // Rearrange nodes
        node* temp = parent;
        child->right = temp;
        temp->left = y;
    }
    else {
        node* y = child->left;
        node* temp = parent;
        child->left = temp;
        temp->right = y;
    }
}

void rotateLeft(node* x) {
    node *y = x -> right;
    x -> right = y -> left;
    y -> left = x;
    // return y;
}

void rotateRight(node *x) {
    node *y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    // return y;
}

// Splay t to root
node* splay(node* x) {
    while (x -> parent != nullptr) {
        if (x -> parent -> parent == nullptr) {
            if (x == x -> parent -> left) {
                // zig rotation
                rotateRight(x -> parent);
            }
            else if (x == x -> parent -> right) {
                // zag rotation
                rotateLeft(x -> parent);
            }
            else if (x == x -> parent -> left && x -> parent == x -> parent -> parent -> left) {
                // zig-zig rotation
                rotateRight(x -> parent -> parent);
                rotateRight(x -> parent);
            }
            else if (x == x -> parent -> right && x -> parent == x -> parent -> parent -> right) {
                // zag-zag rotation
                rotateLeft(x -> parent -> parent);
                rotateLeft(x -> parent);
            }
            else if (x == x -> parent -> right && x -> parent == x -> parent -> parent -> left) {
                // zig-zag rotation
                rotateLeft(x -> parent);
                rotateRight(x -> parent);
            }
            else {
                // zag-zig rotation
                rotateRight(x -> parent);
                rotateLeft(x -> parent);
            }
        }
    }
    return(x);
}
