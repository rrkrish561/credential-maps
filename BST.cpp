#include "BST.h"

BST::~BST() { deleteNodes(_root); }

BST::BST() {
  _size = 0;
  _root = nullptr;
}

void BST::deleteNodes(TreeNode *currnode) { // not tail recursive, may cause overflow
  if (currnode != nullptr) {
    deleteNodes(currnode->getLeft());
    deleteNodes(currnode->getRight());
    delete currnode;
  }
}

void BST::Insert(string key, string value) { insertNode(key, value); }
string BST::Search(string key) { return getNode(key)->getValue(); }

void BST::insertNode(string key, string value) {
  TreeNode *newnode = new TreeNode(key, value);
  if (_size == 0) {
    _root = newnode;
    _size++;
  } else {
    TreeNode *currnode = _root;
    TreeNode *prevnode;
    bool lower = false;

    while (currnode != nullptr) {
      string currnode_key = currnode->getKey();
      if (key == currnode_key) { // if the keys are equal
        prevnode = nullptr; // duplicate found, do not insert anything
        currnode = nullptr;
        delete newnode;
      } else {
        lower = key < currnode_key;
        if (lower) {
          prevnode = currnode;
          currnode = currnode->getLeft();
        } else {
          prevnode = currnode;
          currnode = currnode->getRight();
        }
      }
    }

    if (prevnode != nullptr) {
      if (lower)
        prevnode->setLeft(newnode);
      else
        prevnode->setRight(newnode);
      _size++;
    }
  }
}

BST::TreeNode *BST::getNode(string key) {
  if (_size == 0) {
    return nullptr;
  } else {
    BST::TreeNode *currnode = _root;
    while (currnode != nullptr) {
      string currnode_key = currnode->getKey();
      if (key == currnode_key) {
        return currnode;
      } else {
        bool lower = key < currnode_key;
        if (lower)
          currnode = currnode->getLeft();
        else
          currnode = currnode->getRight();
      }
    }
    return nullptr;
  }
}

BST::TreeNode::TreeNode(string key, string value) {
  _key = key;
  _value = value;
  _left = nullptr;
  _right = nullptr;
}

void BST::TreeNode::setLeft(TreeNode *left) { _left = left; }
void BST::TreeNode::setRight(TreeNode *right) { _right = right; }
string BST::TreeNode::getKey() { return _key; }
string BST::TreeNode::getValue() { return _value; }
BST::TreeNode *BST::TreeNode::getLeft() { return _left; }
BST::TreeNode *BST::TreeNode::getRight() { return _right; }
