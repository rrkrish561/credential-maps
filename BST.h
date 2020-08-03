#include "Tree.h"
#include <iostream>
#include <string>
using namespace std;

struct BST : public Tree {
private:
  TreeNode* getNode(string _key);
  void insertNode(string _key, string _value);
public:
  ~BST();
  BST();
  void Insert(string _key, string _value);
  string Search(string _key);
};
