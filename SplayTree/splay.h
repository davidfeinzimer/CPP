#ifndef SPLAY_H
#define SPLAY_H

// Node structure
struct node {
    int key;
    node* left;
    node* right;
    node* parent;
};

void rotate(node* child, node* parent);     // Rotation
bool find(node*& root, int value);          // Search
node* insert(node* root, int value);        // Insertion
//node* remove(node* root, int value);      // Deletion
node* splay(node* t);                       // Splay

#endif
