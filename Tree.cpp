#include "Tree.h"

Tree::~Tree() {
  deleteTree(root);
}

void Tree::deleteTree(Tree::TreeNode* tempRoot) {
  if(tempRoot != nullptr) {
    deleteTree(tempRoot->left);
    deleteTree(tempRoot->right);
    delete tempRoot;
  }
}

int Tree::getSize() {
  return size;
}