#include "SplayTree.h"

using namespace std;

SplayTree::SplayTree() { root = nullptr; size = 0;}

void SplayTree::Insert(string key, string value) {
  TreeNode *temp = new TreeNode(key, value);

  if (root == nullptr) {
    root = temp;
    size++;
  } else {
    insertHelper(root, temp);
  }

  root = Splay(root, temp);
}

void SplayTree::insertHelper(Tree::TreeNode *tempRoot, Tree::TreeNode *temp) {
  bool alreadyExists = false;

  if (temp->key < tempRoot->key) {
    if (tempRoot->left == nullptr) {
      tempRoot->left = temp;
      size++;
    } else
      insertHelper(tempRoot->left, temp);
  } else if (temp->key > tempRoot->key) {
    if (tempRoot->right == nullptr) {
      tempRoot->right = temp;
      size++;
    } else
       alreadyExists = true;
  } 

  if (alreadyExists == true)
    delete temp;
}

string SplayTree::Search(string key) { return searchHelper(root, key); }

string SplayTree::searchHelper(Tree::TreeNode *tempRoot, string key) {
  if (tempRoot == nullptr) {
    return std::string();
  } else if (key == tempRoot->key) {
    root = Splay(root, tempRoot);
    return tempRoot->value;
  } else if (key < tempRoot->key) {
    return searchHelper(tempRoot->left, key);
  } else {
    return searchHelper(tempRoot->right, key);
  }
}

Tree::TreeNode* SplayTree::Splay(Tree::TreeNode *tempRoot,
                                      TreeNode *node) {
  if (node == tempRoot || tempRoot == nullptr) {
    return tempRoot;
  }

  if (node->key < tempRoot->key) {
    if (tempRoot->left == nullptr)
      return tempRoot;

    if (node->key < tempRoot->left->key) {
      tempRoot->left->left = Splay(tempRoot->left->left, node);
      tempRoot->left = rightRotate(tempRoot->left);
    } else if (node->key > tempRoot->left->key) {
      tempRoot->left->right = Splay(tempRoot->left->right, node);
      tempRoot->left = leftRotate(tempRoot->left);
    }

    tempRoot = rightRotate(tempRoot);
    return tempRoot;
  } else {
    if (tempRoot->right == nullptr)
      return tempRoot;

    if (node->key > tempRoot->right->key) {
      tempRoot->right->right = Splay(tempRoot->right->right, node);
      tempRoot->right = leftRotate(tempRoot->right);
    } else if (node->key < tempRoot->right->key) {
      tempRoot->right->left = Splay(tempRoot->right->left, node);
      tempRoot->right = rightRotate(tempRoot->right);
    }
    tempRoot = leftRotate(tempRoot);
    return tempRoot;
  }
}

Tree::TreeNode* SplayTree::rightRotate(Tree::TreeNode *tempRoot) {
  TreeNode *tempLeft = tempRoot->left;
  tempRoot->left = tempLeft->right;
  tempLeft->right = tempRoot;

  return tempLeft;
}

Tree::TreeNode* SplayTree::leftRotate(Tree::TreeNode *tempRoot) {
  TreeNode *tempRight = tempRoot->right;
  tempRoot->right = tempRight->left;
  tempRight->left = tempRoot;

  return tempRight;
}