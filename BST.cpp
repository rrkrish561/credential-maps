#include "BST.h"

BST::BST() {
  size = 0;
  root = nullptr;
}

void BST::Insert(string _key, string _value) { insertNode(_key, _value); }
string BST::Search(string _key) { return getNode(_key)->value; }

void BST::insertNode(string _key, string _value) {
  TreeNode *newnode = new TreeNode(_key, _value);
  if (size == 0) {
    root = newnode;
    size++;
  } else {
    TreeNode *currnode = root;
    TreeNode *prevnode;
    bool lower = false;

    while (currnode != nullptr) {
      string currnode_key = currnode->key;
      if (_key == currnode_key) { // if the keys are equal
        prevnode = nullptr; // duplicate found, do not insert anything
        currnode = nullptr;
        delete newnode;
      } else {
        lower = _key < currnode_key;
        if (lower) {
          prevnode = currnode;
          currnode = currnode->left;
        } else {
          prevnode = currnode;
          currnode = currnode->right;
        }
      }
    }

    if (prevnode != nullptr) {
      if (lower)
        prevnode->left = newnode;
      else
        prevnode->right = newnode;
      size++;
    }
  }
}

BST::TreeNode *BST::getNode(string _key) {
  if (size == 0) {
    return nullptr;
  } else {
    BST::TreeNode *currnode = root;
    while (currnode != nullptr) {
      string currnode_key = currnode->key;
      if (_key == currnode_key) {
        return currnode;
      } else {
        bool lower = _key < currnode_key;
        if (lower)
          currnode = currnode->left;
        else
          currnode = currnode->right;
      }
    }
    return nullptr;
  }
}